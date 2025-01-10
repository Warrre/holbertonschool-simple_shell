#include "shell.h"

/**
 * execute_command - Executes a command.
 * @args: Array of arguments.
 *
 * Return: 1 to continue, 0 to exit.
 */
int execute_command(char **args)
{
    pid_t pid;
    int status;
    char *cmd_path;

    if (execute_builtin(args))
        return (1);

    cmd_path = is_path_command(args[0]) ? args[0] : find_command_path(args[0]);
    if (!cmd_path)
    {
        perror("Command not found");
        return (1);
    }

    pid = fork();
    if (pid == 0)
    {
        execve(cmd_path, args, environ);
        perror("Execve failed");
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        perror("Fork failed");
    }
    else
    {
        waitpid(pid, &status, 0);
    }

    if (!is_path_command(args[0]))
        free(cmd_path);

    return (1);
}