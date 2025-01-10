#include "shell.h"

/**
 * shell_loop - Main loop of the shell.
 */
void shell_loop(void)
{
    char *line;
    char **args;
    int status = 1;

    while (status)
    {
        write(STDOUT_FILENO, "$ ", 2);
        line = read_input();
        if (!line)
        {
            free(line);
            break;
        }
        args = parse_input(line);
        if (args && args[0])
            status = execute_command(args);
        free(line);
        free_tokens(args);
    }
}

/**
 * read_input - Reads a line of input from stdin.
 *
 * Return: The input line.
 */
char *read_input(void)
{
    char *line = NULL;
    size_t len = 0;

    if (getline(&line, &len, stdin) == -1)
    {
        free(line);
        return (NULL);
    }

    return (line);
}