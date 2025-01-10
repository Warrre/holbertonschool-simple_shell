#include "shell.h"

/**
 * main - Entry point of the shell.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    signal(SIGINT, handle_signal);
    shell_loop();

    return (0);
}

/**
 * handle_signal - Handles SIGINT (Ctrl+C) signal.
 * @sig: Signal number.
 */
void handle_signal(int sig)
{
    (void)sig;
    write(STDOUT_FILENO, "\n$ ", 3);
}