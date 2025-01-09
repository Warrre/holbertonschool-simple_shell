#include "shell.h"

/**
 * find_executable - Trouve le chemin complet d’une commande à l’aide de PATH.
 * @cmd: Commande à rechercher.
 *
 * Return: Chemin complet vers l’exécutable ou NULL si non trouvé.
 */
char *find_executable(char *cmd)
{
    char *path = getenv("PATH");
    char *dir, *full_path;
    size_t len;

    if (path == NULL)
        return NULL;

    path = strdup(path);
    dir = strtok(path, ":");
    while (dir != NULL)
    {
        len = strlen(dir) + strlen(cmd) + 2;
        full_path = malloc(len);
        if (!full_path)
        {
            free(path);
            return NULL;
        }

        snprintf(full_path, len, "%s/%s", dir, cmd);
        if (access(full_path, X_OK) == 0)
        {
            free(path);
            return full_path;
        }

        free(full_path);
        dir = strtok(NULL, ":");
    }

    free(path);
    return NULL;
}