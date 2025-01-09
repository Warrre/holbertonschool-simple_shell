#include "shell.h"

/**
 * main - Point d’entrée de l'interpréteur de commande.
 *
 * Return: 0 en cas de succès.
 */
int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    pid_t pid;
    int status;

    while (1)
    {
        if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, PROMPT, strlen(PROMPT));

        nread = getline(&line, &len, stdin);
        if (nread == -1)
        {
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n", 1);
            break;
        }

        if (line[nread - 1] == '\n')
            line[nread - 1] = '\0';

        if (strlen(line) == 0)
            continue;

        char *args[BUFFER_SIZE];
        size_t i = 0;
        char *token = strtok(line, " ");
        while (token != NULL && i < BUFFER_SIZE - 1)
        {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        if (execute_builtin(args))
            continue;

        char *executable = find_executable(args[0]);
        if (executable == NULL && access(args[0], X_OK) == 0)
            executable = strdup(args[0]);

        if (executable == NULL)
        {
            fprintf(stderr, "%s: command not found\n", args[0]);
            continue;
        }

        pid = fork();
        if (pid == -1)
        {
            perror("fork");
            free(executable);
            continue;
        }

        if (pid == 0)
        {
            if (execve(executable, args, environ) == -1)
            {
                perror(args[0]);
                free(executable);
                exit(EXIT_FAILURE);
            }
        }
        else
            wait(&status);

        free(executable);
    }

    free(line);
    return (0);
}
