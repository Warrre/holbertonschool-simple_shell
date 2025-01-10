#include "shell.h"

/* Exécuter une commande */
void execute_cmd(char **tokens, char *cmd_path, char **argv, int cmd_count)
{
    pid_t pid = fork();
    if (pid == 0) {
        execvp(tokens[0], tokens);
        perror("Exécution échouée");
        exit(1);
    } else if (pid < 0) {
        perror("Erreur fork");
    } else {
        wait(NULL);
    }
}

/* Cherche le chemin de la commande dans les répertoires PATH */
char *search_path(void)
{
    char *path = getenv("PATH");
    return path ? path : "/bin:/usr/bin";
}
