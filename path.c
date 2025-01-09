#include "simple_shell.h"

/**
 * find_in_path - Recherche le chemin complet d'une commande dans PATH.
 * @cmd: Nom de la commande.
 * Return: Le chemin complet de la commande ou NULL si non trouvé.
 */
char *find_in_path(char *cmd)
{
    char *path = getenv("PATH"); /* Récupère la variable d'environnement PATH */
    char *token = strtok(path, ":"); /* Sépare les répertoires du PATH */
    char *full_path = NULL;

    while (token != NULL)
    {
        full_path = malloc(strlen(token) + strlen(cmd) + 2); /* Alloue de la mémoire */
        if (full_path == NULL)
            return (NULL);
        
        strcpy(full_path, token); /* Copie le répertoire */
        strcat(full_path, "/");    /* Ajoute un / */
        strcat(full_path, cmd);    /* Ajoute le nom de la commande */

        if (access(full_path, X_OK) == 0) /* Vérifie si le fichier est exécutable */
        {
            return (full_path); /* Retourne le chemin complet si trouvé */
        }
        free(full_path); /* Libère la mémoire si le chemin n'est pas valide */
        token = strtok(NULL, ":"); /* Passe au répertoire suivant */
    }
    return (NULL); /* Retourne NULL si la commande n'est pas trouvée */
}