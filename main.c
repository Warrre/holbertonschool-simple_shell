#include "simple_shell.h"

/**
 * main - Point d'entrée du programme.
 * @argc: Nombre d'arguments passés au programme.
 * @argv: Tableau des arguments passés au programme.
 * Return: 0 si succès, 1 si erreur.
 */
int main(int argc, char **argv)
{
    char *line = NULL;         /* Ligne de commande de l'utilisateur */
    char **args = NULL;        /* Tableau des arguments */
    size_t len = 0;            /* Taille de la ligne de commande */
    ssize_t nread;             /* Nombre d'octets lus */
    int status = 0;            /* Statut de la commande */

    /* Affichage du prompt et traitement des commandes en boucle */
    while (1)
    {
        write(STDOUT_FILENO, "$ ", 2); /* Affiche le prompt */
        nread = getline(&line, &len, stdin); /* Lire la ligne entrée par l'utilisateur */

        if (nread == -1) /* Gestion de la fin de fichier */
        {
            free(line);
            exit(status);
        }

        args = split_line(line); /* Divise la ligne en mots */
        status = execute(args);   /* Exécute la commande */
        free(args);               /* Libère la mémoire de args */
    }

    free(line); /* Libère la mémoire de la ligne de commande */
    return (status);
}
