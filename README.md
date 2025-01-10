# simple_shell

A simple UNIX command-line interpreter 

## Overview

`simple_shell` is a minimalist shell program designed to execute basic commands, process arguments, and handle the PATH environment. This project serves as an introduction to system-level programming in C.

## Features

- Executes system commands using `execve`.
- Handles PATH resolution for commands.
- Built-in commands:
  - `exit`: Exit the shell.
  - `env`: Print the current environment variables.
- Displays a custom prompt.
- Handles end-of-file (Ctrl+D) and signals (e.g., Ctrl+C).
- Works in both interactive and non-interactive modes.

## Usage

To compile the shell, use:

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o simple_shell
```

To run the shell interactively:

```bash
./simple_shell
```

To run a command file non-interactively:

```bash
echo "command" | ./simple_shell
```

## Examples

Interactive mode:

```bash
$ ./simple_shell
#cisfun$ ls
file1  file2  simple_shell
#cisfun$ env
USER=gomes
HOME=/home/warren
...
#cisfun$ exit
```

Non-interactive mode:

```bash
echo "ls" | ./simple_shell
file1  file2  simple_shell
```

## Installation

1. Clone the repository:

```bash
git clone https://github.com/warren-gomes/simple_shell.git
```

2. Navigate to the project directory and compile:

```bash
cd simple_shell
make
```

3. Run the shell:

```bash
./simple_shell
```