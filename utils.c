#include "shell.h"

/**
 * free_args - Libère la mémoire des arguments.
 * @args: Tableau des arguments.
 */
void free_args(char **args)
{
	free(args);
}
