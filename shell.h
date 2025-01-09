#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define PROMPT "#cisfun$ "

extern char **environ;

int execute_builtin(char **args);
char *find_executable(char *cmd);
void free_array(char **array);

#endif /* SHELL_H */