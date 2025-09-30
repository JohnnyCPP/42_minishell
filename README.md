# Minishell

The Minishell project is a part of the 42 School curriculum where students create a simplified version of a Unix shell.
The goal is to understand how a command-line interpreter works by implementing one from scratch.

## Project Overview

![42](./resources/42_madrid.jpg "42")

> 42 Madrid is an academy for values, attitude and learning "hard and soft skills" in the digital environment.

Developed by JohnnyCPP and tdaroca.

Minishell is a command-line interpreter that can parse and execute user commands, providing a hands-on exploration of core system programming concepts like process creation, file descriptor management, and signal handling.

Here's a list of implemented features:

- Command execution: Simple commands with absolute, relative, or no path
- Built-in commands: echo (with -n), cd, pwd, export, unset, env, and exit
- Redirections and pipes: Input/output redirection (<, >, >>), pipes (|), and here-doc (<<)
- Parsing and variable expansion: Handling single (' ') and double quotes (" "), environment variable expansion ($VAR)
- Signal handling: Responding to Ctrl-C (SIGINT), Ctrl-\ (SIGQUIT), and Ctrl-D (EOF) like in bash

## Run

Clone the repository and run the following make targets:

```bash
git clone https://github.com/JohnnyCPP/42_minishell.git
cd 42_minishell
make help
make all
./minishell
# interactive prompt will be displayed here
```

