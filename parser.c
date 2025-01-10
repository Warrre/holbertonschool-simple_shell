#include "shell.h"

/**
 * parse_input - Tokenizes the input string.
 * @line: The input string.
 *
 * Return: Array of tokens.
 */
char **parse_input(char *line)
{
    char **tokens;
    char *token;
    size_t bufsize = 64, i = 0;

    tokens = malloc(sizeof(char *) * bufsize);
    if (!tokens)
    {
        perror("Error");
        return (NULL);
    }

    token = strtok(line, " \n");
    while (token)
    {
        tokens[i++] = strdup(token);
        token = strtok(NULL, " \n");
    }
    tokens[i] = NULL;

    return (tokens);
}