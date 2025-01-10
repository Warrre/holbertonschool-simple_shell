# Simple Shell

## Description
This project is a simple UNIX command line interpreter that replicates the basic functionality of a shell. It supports executing commands, handling errors, and interacting with the environment.

## Features
- Display a prompt and wait for user input.
- Execute commands from the user input.
- Handle commands with or without arguments.
- Search for commands in the `PATH`.
- Handle built-in commands like `exit` and `env`.
- Manage errors gracefully (e.g., command not found).
- Support both interactive and non-interactive modes.

## Requirements
- The program is compiled with:
  ```bash
  gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
  ```
- The shell should behave exactly like `/bin/sh` for most operations.

## Usage
### Interactive Mode
Run the shell and use commands directly:
```bash
./hsh
$ ls
$ pwd
$ exit
```

### Non-Interactive Mode
Feed commands via a pipe or a file:
```bash
echo "ls -l" | ./hsh
cat commands.txt | ./hsh
```

## Allowed Functions and System Calls
The following functions and system calls are used in this project:
- `access`, `chdir`, `close`, `closedir`, `execve`, `exit`, `_exit`, `fflush`, `fork`, `free`, `getcwd`, `getline`, `getpid`, `isatty`, `kill`, `malloc`, `open`, `opendir`, `perror`, `read`, `readdir`, `signal`, `stat`, `lstat`, `fstat`, `strtok`, `wait`, `waitpid`, `wait3`, `wait4`, `write`.

## File Structure
| File        | Description                                           |
|-------------|-------------------------------------------------------|
| `main.c`    | Entry point of the shell program.                     |
| `shell.c`   | Core shell functions like command execution.          |
| `parser.c`  | Functions to parse and tokenize user input.           |
| `path.c`    | Functions to handle command searching in `PATH`.      |
| `env.c`     | Built-in function to print the environment variables. |
| `utils.c`   | Helper functions like freeing memory.                 |
| `shell.h`   | Header file containing prototypes and macros.         |

## Example Output
### Interactive Mode:
```bash
$ ./hsh
$ /bin/ls
main.c shell.c shell.h
$ env
USER=julien
HOME=/home/julien
PATH=/usr/bin:/bin
$ exit
```

### Non-Interactive Mode:
```bash
echo "ls" | ./hsh
main.c shell.c shell.h
```

## Authors
-warren Gomes Martins-