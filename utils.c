#include "simple_shell.h"

/**
 * split_line - Divise la ligne de commande en arguments.
 * @line: Ligne de commande à diviser.
 * Return: Tableau de chaînes de caractères (les arguments).
 */
char **split_line(char *line)
{
    int bufsize = 64, position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;

    if (!tokens)
    {
        perror("allocation error");
        exit(1);
    }

    token = strtok(line, " \t\r\n\a"); /* Divise la ligne par espace/tabulation/nouvelle ligne */
    while (token != NULL)
    {
        tokens[position] = token;
        position++;

        if (position >= bufsize)
        {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens)
            {
                perror("allocation error");
                exit(1);
            }
        }
        token = strtok(NULL, " \t\r\n\a"); /* Récupère le prochain token */
    }
    tokens[position] = NULL; /* Ajoute NULL à la fin du tableau */
    return tokens;
}

/**
 * execute - Exécute une commande.
 * @args: Tableau d'arguments.
 * Return: 1 si commande réussie, 0 sinon.
 */
int execute(char **args)
{
    pid_t pid, wpid;
    int status;

    if (args[0] == NULL) /* Si aucune commande n'est donnée */
        return (1);

    if (strcmp(args[0], "exit") == 0) /* Commande exit */
        return (_exit_shell(args));

    if (strcmp(args[0], "cd") == 0) /* Commande cd */
        return (_cd(args));

    pid = fork(); /* Crée un nouveau processus */

    if (pid == 0) /* Processus enfant */
    {
        char *cmd_path = find_in_path(args[0]); /* Cherche le chemin complet de la commande */
        if (cmd_path == NULL)
        {
            perror(args[0]); /* Affiche l'erreur si la commande n'est pas trouvée */
            exit(1);
        }

        if (execve(cmd_path, args, NULL) == -1) /* Exécute la commande */
        {
            perror("execve");
        }
        free(cmd_path);
        exit(1);
    }
    else if (pid < 0) /* Erreur de fork */
    {
        perror("fork");
    }
    else
    {
        do
        {
            wpid = waitpid(pid, &status, WUNTRACED); /* Attente de la fin du processus enfant */
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return (1);
}
