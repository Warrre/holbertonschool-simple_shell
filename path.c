#include "simple_shell.h"

/**
 * find_in_path - Recherche la commande dans les répertoires du PATH.
 * @cmd: Nom de la commande.
 * Return: Le chemin complet de la commande ou NULL si non trouvé.
 */
char *find_in_path(char *cmd)
{
    char *path = getenv("PATH"); /* Récupère la variable d'environnement PATH */
    char *token = strtok(path, ":"); /* Sépare les répertoires */
    char *full_path = NULL;

    while (token != NULL)
    {
        full_path = malloc(strlen(token) + strlen(cmd) + 2); /* Allocation mémoire pour le chemin */
        if (full_path == NULL)
            return (NULL);

        strcpy(full_path, token); /* Copie le répertoire */
        strcat(full_path, "/");    /* Ajoute un '/' pour concaténer la commande */
        strcat(full_path, cmd);    /* Ajoute le nom de la commande */

        if (access(full_path, X_OK) == 0) /* Vérifie si la commande est exécutable */
        {
            return (full_path);
        }

        free(full_path); /* Libère la mémoire si la commande n'est pas trouvée */
        token = strtok(NULL, ":"); /* Passe au répertoire suivant dans le PATH */
    }
    return (NULL);
}