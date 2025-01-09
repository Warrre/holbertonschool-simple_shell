#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define PROMPT "#cisfun$ "

extern char **environ;

/**
 * find_executable - Finds the full path of a command using PATH.
 * @cmd: Command to search for.
 *
 * Return: Full path to the executable or NULL if not found.
 */
char *find_executable(char *cmd)
{
    char *path = getenv("PATH");
    char *dir, *full_path;
    size_t len;

    if (path == NULL)
        return NULL;

    dir = strtok(path, ":");
    while (dir != NULL)
    {
        len = strlen(dir) + strlen(cmd) + 2;
        full_path = malloc(len);
        if (!full_path)
            return NULL;

        snprintf(full_path, len, "%s/%s", dir, cmd);
        if (access(full_path, X_OK) == 0)
            return full_path;

        free(full_path);
        dir = strtok(NULL, ":");
    }

    return NULL;
}

/**
 * execute_builtin - Executes built-in commands.
 * @args: Array of arguments.
 *
 * Return: 1 if a built-in command was executed, 0 otherwise.
 */
int execute_builtin(char **args)
{
    if (strcmp(args[0], "exit") == 0)
    {
        exit(args[1] ? atoi(args[1]) : 0);
    }
    else if (strcmp(args[0], "env") == 0)
    {
        for (char **env = environ; *env; ++env)
            printf("%s\n", *env);
        return 1;
    }
    else if (strcmp(args[0], "cd") == 0)
    {
        if (args[1] == NULL)
            fprintf(stderr, "cd: missing argument\n");
        else if (chdir(args[1]) != 0)
            perror("cd");
        return 1;
    }

    return 0;
}
