#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

/* Prototypes des fonctions */
int _exit_shell(char **args);
int _cd(char **args);
char *find_in_path(char *cmd);
char **split_line(char *line);
int execute(char **args);
void free_memory(char **args);

#endif /* SIMPLE_SHELL_H */