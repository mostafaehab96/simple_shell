# 0x16. C - Simple Shell
This is the second group project in alx software engineering program, first sprint **low_level_programming** , it's about creating a simple shell program that acts like [Bourne shell](https://en.wikipedia.org/wiki/Unix_shell) `sh`
___
## Functions and system calls we used
* `access` (man 2 access)
* `chdir` (man 2 chdir)
* `execve` (man 2 execve)
* `exit` (man 3 exit)
* `fork` (man 2 fork)
* `getline` (man 3 getline)
* `getpid` (man 2 getpid)
* `isatty` (man 3 isatty)
* `malloc` (man 3 malloc)
* `realloc` (man 3 realloc)
* `perror` (man 3 perror)
* `strtok` (man 3 strtok)
* `wait` (man 2 wait)
* `fprintf` (man 3 fprintf)
___
## Files Structure

|  ***File***  | ***Description***     |
|-------------|------------------------|
| [main.h](./main.h) | Header file with functions prototypes and structures |
| [shell.c](./shell.c) | Main File to execute |
| [str_func.c](./str_func.c) | File containing functions to help with string manipulation |
| [helpers.c](./helpers.c) | File containing functions to help with PATH and arguments handling |
| [builtins.c](./builtins.c) | File containing buitins like cd, env etc... |
| [exec.c](./exec.c) | File containing helper functions that deals with reading input, excuting commands and checking main arguments |
| [list_func.c](./list_func.c) | File containing functions that deals with linked list functions |
| [tokenize.c](./tokenize.c) | File containing functions that deals with string tokenization of strings |
___
## How to compile and run
* Compile with `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`
* Run `./hsh`
___
## Features
* Handles the command with it's path `/bin/ls`
* Handles the command without it's path `ls`
* Handles the command with arguments `ls -la /home`
* Handles builtins like `cd` , `env` `exit 98`, `setenv` and `unsetenv`
* Doesn't handle the command separation with `;`
___
## Authors
* **Mostafa Ehab** - [mostafaehab96](github.com/mostafaehab)
*  **Iman Hamza** - [Imanhamza](github.com/Imanhamza)
