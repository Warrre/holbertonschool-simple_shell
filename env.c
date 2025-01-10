#include "shell.h"

/* Afficher toutes les variables d'environnement */
void show_environment(void)
{
    int i = 0;
    while (environ[i] != NULL) {
        printf("%s\n", environ[i]);
        i++;
    }
}

/* Récupérer une variable d'environnement par son nom */
char *get_environment_variable(const char *name)
{
    return getenv(name);
}
