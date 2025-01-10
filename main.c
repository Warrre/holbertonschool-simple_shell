#include "shell.h"

/**
 * main - Point d'entrée du shell.
 * @argc: Nombre d'arguments.
 * @argv: Tableau des arguments.
 * @env: Tableau de l'environnement.
 * Return: 0 en cas de succès.
 */
int main(int argc, char **argv, char **env)
{
	char *line = NULL, **args = NULL;
	size_t len = 0;
	ssize_t nread;
	int status = 1;

	(void)argc;

	while (status)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			free(line);
			exit(0);
		}

		line[nread - 1] = '\0'; /* Supprime le saut de ligne */
		args = parse_input(line);
		if (args && args[0])
			status = execute_command(args, argv[0], env);
		free_args(args);
	}

	free(line);
	return (0);
}
