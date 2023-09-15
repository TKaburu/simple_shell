# Simple Shell Project

This project is a UNIX command line interpreter, also known as a shell. It provides a command line interface where users can enter commands to be executed. The shell reads the commands, executes them, and displays the results to the user.

## Usage

To use the shell, you can run the `./hsh` executable. Once started, the shell will display a prompt and wait for the user to enter a command. The prompt is displayed after each command execution.

The shell supports simple command lines. It handles advanced features such as semicolons, pipes, redirections, or special characters.

If an executable cannot be found, the shell will print an error message and display the prompt again.

The shell can be used in both interactive and non-interactive mode:

### Interactive Mode

In interactive mode, you can directly enter commands into the shell's prompt:

```
$ ./simple_shell
($) /bin/ls
file1.txt  file2.txt  directory
($)
($) exit
$
```

### Non-Interactive Mode

In non-interactive mode, you can pass commands to the shell through standard input (e.g., using pipes or input redirection):

```
$ echo "/bin/ls" | ./simple_shell
file1.txt  file2.txt  directory
```

## Compilation

To compile the shell, you can use the following command:

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Features

### Simple Shell 0.1

- Displays a prompt and waits for the user to enter a command.
- Executes the command and displays the output.
- Handles errors when an executable cannot be found.
- Handles the "end of file" condition (Ctrl+D) to exit the shell.

### Simple Shell 0.2

- Handles command lines with arguments. Commands can have additional words as arguments.
- Supports executing commands located in the PATH environment variable.
- Does not call fork if the command does not exist.

### Simple Shell 0.3

- Handles the PATH environment variable for command execution.
- Does not call fork if the command does not exist.

### Simple Shell 0.4

- Implements the built-in exit command to exit the shell.

### Simple Shell 1.0

- Implements the built-in env command to print the current environment.

### Simple Shell 0.1.1 (Advanced)

- Implements a custom getline function to read input from the user.

### Simple Shell 0.2.1 (Advanced)

- Does not use the strtok function for parsing command lines.

### Simple Shell 0.4.1 (Advanced)

- Handles arguments for the built-in exit command, allowing users to specify an exit status.

### setenv, unsetenv (Advanced)

- Implements the built-in setenv and unsetenv commands to manage environment variables.

### cd (Advanced)

- Implements the built-in cd command to change the current directory.

### ; (Advanced)

- Handles the ; separator to execute multiple commands in sequence.

### && and || (Advanced)

- Handles the && and || operators for conditional command execution.

## Allowed Functions and System Calls

The shell is implemented using a set of allowed functions and system calls, including but not limited to:

- access
- chdir
- close
- closedir
- execve
- exit
- _exit
- fflush
- fork
- free
- getcwd
- getline
- getpid
- isatty
- kill
- malloc
- open
- opendir
- perror
- read
- readdir
- signal
- stat (__xstat)
- lstat (__lxstat)
