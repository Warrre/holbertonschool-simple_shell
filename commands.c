#include "shell.h"

/* Exit le shell */
int exit_shell(char **tokens)
{
    if (tokens[1] != NULL)
        printf("Exit avec un argument non valide\n");
    exit(0);
}

/* Changer de répertoire avec la commande `cd` */
int change_directory(char **tokens, int cmd_count, char **argv)
{
    if (tokens[1] == NULL) {
        chdir(getenv("HOME"));
    } else if (chdir(tokens[1]) != 0) {
        perror("cd");
    }
    return 1;
}

/* Vérifie si la commande est interne */
int is_builtin_command(char *cmd)
{
    return compare_strings(cmd, "exit") == 0 || compare_strings(cmd, "cd") == 0 || compare_strings(cmd, "env") == 0;
}
