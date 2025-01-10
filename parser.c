#include "shell.h"

char **parse_input(char *input)
{
    char **args = NULL;
    char *token;
    size_t i = 0, size = 10;

    args = malloc(sizeof(char *) * size);
    if (!args)
        return (NULL);

    token = strtok(input, " \n\t");
    while (token)
    {
        args[i++] = strdup(token);
        if (i >= size)
        {
            size += 10;
            args = realloc(args, sizeof(char *) * size);
            if (!args)
                return (NULL);
        }
        token = strtok(NULL, " \n\t");
    }
    args[i] = NULL;
    return (args);
}

void free_args(char **args)
{
    size_t i = 0;

    if (!args)
        return;

    while (args[i])
        free(args[i++]);

    free(args);
}