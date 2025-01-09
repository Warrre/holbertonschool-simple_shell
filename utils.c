#include "simple_shell.h"

/**
 * split_line - Divise la ligne de commande en arguments.
 * @line: La ligne de commande à diviser.
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

    token = strtok(line, " \t\r\n\a"); /* Sépare la ligne par espace, tabulation ou nouvelle ligne */
    while (token != NULL)
    {
        tokens[position] = token;
        position++;

        if (position >= bufsize) /* Si le tableau est plein, réalloue de la mémoire */
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
    tokens[position] = NULL; /* Terminer le tableau par NULL */
    return tokens;
}

/**
 * execute - Exécute la commande dans un processus enfant.
 * @args: Tableau des arguments.
 * Return: 1 si succès, 0 sinon.
 */
int execute(char **args)
{
    pid_t pid, wpid;
    int status;

    if (args[0] == NULL) /* Si aucune commande n'est entrée */
        return (1);

    /* Commandes internes (builtins) */
    if (strcmp(args[0], "exit") == 0) /* Commande exit */
        return (_exit_shell(args));
    if (strcmp(args[0], "cd") == 0)   /* Commande cd */
        return (_cd(args));

    pid = fork(); /* Crée un processus fils */

    if (pid == 0) /* Processus fils */
    {
        char *cmd_path = find_in_path(args[0]); /* Cherche la commande dans le PATH */
        if (cmd_path == NULL)
        {
            perror(args[0]);
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
            wpid = waitpid(pid, &status, WUNTRACED); /* Attend la fin du processus fils */
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return (1);
}

/**
 * free_memory - Libère la mémoire allouée pour les arguments.
 * @args: Tableau des arguments.
 */
void free_memory(char **args)
{
    int i = 0;
    while (args[i] != NULL)
    {
        free(args[i]);
        i++;
    }
    free(args); /* Libère le tableau d'arguments */
}
