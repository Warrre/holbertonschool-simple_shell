#include "shell.h"

/**
 * free_array - Libère un tableau de pointeurs.
 * @array: Tableau à libérer.
 */
void free_array(char **array)
{
    for (size_t i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}