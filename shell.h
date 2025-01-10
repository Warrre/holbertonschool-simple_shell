#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>

/* Prototypes */

int simple_shell(char *prog_name, char **env);
char **parse_input(char *input);
void free_args(char **args);
int find_command(char *cmd, char **env);
char *getenv_path(char **env);
void print_env(char **env);

#endif /* SHELL_H */
