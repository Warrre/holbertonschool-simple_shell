#include "shell.h"

/**
 * free_tokens - Frees an array of tokens.
 * @tokens: Array of tokens.
 */
void free_tokens(char **tokens)
{
    size_t i;

    for (i = 0; tokens[i]; i++)
        free(tokens[i]);
    free(tokens);
}