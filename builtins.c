#include "simple_shell.h"

/**
 * _exit_shell - Gère la commande exit.
 * @args: Arguments de la commande.
 * Return: 0, ce qui arrête le programme.
 */
int _exit_shell(char **args)
{
    (void)args;
    return (0); /* Quitte le programme */
}

/**
 * _cd - Change le répertoire actuel.
 * @args: Arguments de la commande.
 * Return: 1 si réussi, 0 sinon.
 */
int _cd(char **args)
{
    if (args[1] == NULL) /* Si aucun répertoire n'est passé */
    {
        chdir(getenv("HOME")); /* Va dans le répertoire home */
    }
    else if (chdir(args[1]) != 0) /* Change de répertoire */
    {
        perror("cd"); /* Affiche une erreur en cas de problème */
    }
    return (1);
}