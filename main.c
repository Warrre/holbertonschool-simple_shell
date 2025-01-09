#include "simple_shell.h"

/**
 * main - Point d'entrée du programme.
 * @argc: Nombre d'arguments passés au programme.
 * @argv: Tableau des arguments passés au programme.
 * Return: 0 si succès, 1 si erreur.
 */
int main(int argc, char **argv)
{
    char *line = NULL;
    char **args;
    size_t len = 0;
    ssize_t nread;
    int status = 1;

    (void)argc; /* Evite les warnings sur des paramètres inutilisés */
    (void)argv;

    while (1)
    {
        write(STDOUT_FILENO, "$ ", 2); /* Affiche le prompt */
        nread = getline(&line, &len, stdin); /* Lit la ligne de commande */

        if (nread == -1) /* Si fin de fichier ou erreur de lecture */
        {
            free(line);
            exit(status);
        }

        args = split_line(line); /* Divise la ligne en arguments */
        status = execute(args);   /* Exécute la commande */
        free_memory(args);        /* Libère la mémoire allouée pour les arguments */
    }

    free(line); /* Libère la mémoire allouée pour la ligne de commande */
    return (status);
}
