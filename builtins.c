#include "shell.h"

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
        exit(0);
    }
    if (strcmp(args[0], "cd") == 0)
    {
        return (change_directory(args));
    }
    if (strcmp(args[0], "env") == 0)
    {
        print_environment();
        return (1);
    }
    return (0);
}

/**
 * change_directory - Changes the current directory.
 * @args: Array of arguments.
 *
 * Return: 1 on success.
 */
int change_directory(char **args)
{
    if (!args[1])
        return (chdir(getenv("HOME")));

    if (chdir(args[1]) != 0)
        perror("cd");

    return (1);
}

/**
 * print_environment - Prints the environment variables.
 */
void print_environment(void)
{
    char **env = environ;

    while (*env)
    {
        write(STDOUT_FILENO, *env, strlen(*env));
        write(STDOUT_FILENO, "\n", 1);
        env++;
    }
}