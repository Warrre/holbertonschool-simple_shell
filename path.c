#include "shell.h"

/**
 * is_path_command - Checks if a command is a valid path.
 * @cmd: Command to check.
 *
 * Return: 1 if valid path, 0 otherwise.
 */
int is_path_command(char *cmd)
{
    return (cmd[0] == '/' || strncmp(cmd, "./", 2) == 0);
}

/**
 * find_command_path - Finds the full path of a command.
 * @cmd: Command to find.
 *
 * Return: Full path of command or NULL.
 */
char *find_command_path(char *cmd)
{
    char *path = getenv("PATH"), *dir, *full_path;
    size_t len;

    if (!path)
        return (NULL);

    dir = strtok(path, ":");
    while (dir)
    {
        len = strlen(dir) + strlen(cmd) + 2;
        full_path = malloc(len);
        if (!full_path)
        {
            perror("Error");
            return (NULL);
        }
        snprintf(full_path, len, "%s/%s", dir, cmd);
        if (access(full_path, X_OK) == 0)
            return (full_path);
        free(full_path);
        dir = strtok(NULL, ":");
    }

    return (NULL);
}