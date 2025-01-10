#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>

extern char **environ;

void shell_loop(void);
char *read_input(void);
char **parse_input(char *line);
int execute_command(char **args);
int execute_builtin(char **args);
int change_directory(char **args);
void handle_signal(int sig);
int is_path_command(char *cmd);
char *find_command_path(char *cmd);
void free_tokens(char **tokens);
void print_environment(void);

#endif