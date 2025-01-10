#include "shell.h"

void print_env(char **env)
{
    size_t i = 0;

    while (env[i])
    {
        write(STDOUT_FILENO, env[i], strlen(env[i]));
        write(STDOUT_FILENO, "\n", 1);
        i++;
    }
}