#include "shell.h"

/* Diviser la ligne de commande en tokens */
char **split_command_line(char *line, int *token_count)
{
    char **tokens = malloc(64 * sizeof(char *));
    char *token;
    int pos = 0;

    token = strtok(line, " \t\r\n\a");
    while (token != NULL) {
        tokens[pos] = token;
        pos++;
        token = strtok(NULL, " \t\r\n\a");
    }
    tokens[pos] = NULL;
    *token_count = pos;
    return tokens;
}
