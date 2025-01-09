#include "shell.h"

/**
 * execute_builtin - Exécute les commandes intégrées du shell.
 * @args: Tableau d’arguments.
 *
 * Return: 1 si une commande intégrée est exécutée, 0 sinon.
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