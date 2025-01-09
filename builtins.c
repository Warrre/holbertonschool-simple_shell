#include "simple_shell.h"

/**
 * _exit_shell - Gère la commande exit du shell.
 * @args: Tableau d'arguments.
 * Return: 0 si exit, 1 sinon.
 */
int _exit_shell(char **args)
{
    (void)args; /* Évite le warning si non utilisé */
    exit(0);    /* Sort du shell avec un code de succès */
}

/**
 * _cd - Gère la commande cd pour changer de répertoire.
 * @args: Tableau d'arguments.
 * Return: 1 si succès, 0 sinon.
 */
int _cd(char **args)
{
    if (args[1] == NULL) /* Si aucun argument n'est passé, va au répertoire home */
    {
        chdir(getenv("HOME"));
    }
    else if (chdir(args[1]) != 0) /* Change de répertoire selon l'argument */
    {
        perror("cd");
    }
    return (1);
}
