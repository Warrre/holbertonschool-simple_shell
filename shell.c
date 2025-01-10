#include "shell.h"

int simple_shell(char *prog_name, char **env)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    char **args;
    pid_t pid;

    while (1)
    {
        if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, "$ ", 2);

        nread = getline(&line, &len, stdin);
        if (nread == -1)
        {
            free(line);
            break;
        }

        args = parse_input(line);
        if (!args || !args[0])
        {
            free_args(args);
            continue;
        }

        if (strcmp(args[0], "exit") == 0)
        {
            free_args(args);
            free(line);
            break;
        }

        if (strcmp(args[0], "env") == 0)
        {
            print_env(env);
            free_args(args);
            continue;
        }

        if (find_command(args[0], env))
        {
            pid = fork();
            if (pid == 0)
            {
                execve(args[0], args, env);
                perror(prog_name);
                exit(EXIT_FAILURE);
            }
            else
                wait(NULL);
        }
        else
            fprintf(stderr, "%s: command not found\n", prog_name);

        free_args(args);
    }
    return (0);
}