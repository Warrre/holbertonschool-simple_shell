#include "shell.h"

void display_welcome(void)
{
    printf("Bienvenue dans votre shell personnalisé !\n");
}

void display_prompt(int interactive_mode)
{
    if (interactive_mode)
        printf("shell> ");
}

void handle_input(char **tokens, char **argv, int cmd_count, int *is_running, char *line_buf, char *path_buf)
{
    if (tokens[0] == NULL)
        return;

    if (is_builtin_command(tokens[0])) {
        if (strcmp(tokens[0], "exit") == 0) {
            exit_shell(tokens);
            *is_running = 0;
        } else if (strcmp(tokens[0], "cd") == 0) {
            change_directory(tokens, cmd_count, argv);
        } else if (strcmp(tokens[0], "env") == 0) {
            show_environment();
        } else {
            help_message(tokens[0]);
        }
    } else {
        execute_cmd(tokens, search_path(), argv, cmd_count);
    }
}

void shell_loop(char **argv, int interactive_mode)
{
    char *line_buf = NULL;
    char *path_buf = NULL;
    char **tokens = NULL;
    int cmd_count = 0;
    int is_running = 1;

    while (is_running) {
        display_prompt(interactive_mode);
        getline(&line_buf, (size_t *)&cmd_count, stdin);

        tokens = split_command_line(line_buf, &cmd_count);
        handle_input(tokens, argv, cmd_count, &is_running, line_buf, path_buf);

        free(line_buf);
        free(tokens);
    }
}

int main(int argc, char **argv)
{
    int interactive_mode = isatty(fileno(stdin));
    if (interactive_mode)
        display_welcome();

    shell_loop(argv, interactive_mode);
    return 0;
}
