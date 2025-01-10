#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>

extern char **environ;

/* Prototypes modifiés */
int compare_strings(char *str1, char *str2);
int concat_strings(char *dest, char *src);
int copy_string(char *dest, char *src);
char *duplicate_string(char *source);
int string_length(char *str);
char *find_char(char *str, char character);
void show_environment(void);
char *get_environment_variable(const char *name);
void display_welcome(void);
char *search_path(void);
void split_input_line(char *line, char **tokens);
int exit_shell(char **tokens);
int change_directory(char **tokens, int cmd_count, char **argv);
void signal_handler(int sig);
void execute_cmd(char **tokens, char *cmd_path, char **argv, int cmd_count);
void process_cmd(char **tokens, char **argv, int cmd_count, int *is_running,
				 char *line_buf, char *path_buf);
int set_env_variable(char **tokens);
int unset_env_variable(char **tokens);
void shell_loop(char **argv, int interactive_mode);
int is_builtin_command(char *cmd);
void display_prompt(int interactive_mode);
void handle_input(char **tokens, char **argv, int cmd_count, int *is_running,
				  char *line_buf, char *path_buf);
int convert_to_int(char *str);
void help_message(char *cmd);
char **split_command_line(char *line, int *token_count);

#endif
