# 0x16. C - Simple Shell
This is the second group project in alx software engineering program, first sprint **low_level_programming** , it's about creating a simple shell program that acts like [Bourne shell](https://en.wikipedia.org/wiki/Unix_shell) `sh`
___
## Library Functions and System Calls
* [`access`](https://manual.cs50.io/2/access)
* [`chdir`](https://manual.cs50.io/2/chdir)
* [`execve`](https://manual.cs50.io/2/execve)
* [`exit`](https://manual.cs50.io/2/exit)
* [`fork`](https://manual.cs50.io/2/fork)
* [`getline`](https://manual.cs50.io/3/getline)
* [`getpid`](https://manual.cs50.io/2/getpid)
* [`isatty`](https://manual.cs50.io/3/isatty)
* [`malloc`](https://manual.cs50.io/3/malloc)
* [`realloc`](https://manual.cs50.io/3/realloc)
* [`perror`](https://manual.cs50.io/3/perror)
* [`strtok`](https://manual.cs50.io/3/strtok)
* [`wait`](https://manual.cs50.io/2/wait)
* [`fprintf`](https://manual.cs50.io/3/fprintf)
* [`atoi`](https://manual.cs50.io/3/atoi)
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
* Handles the command separation with `;`
* Doesn't handle separation with (&&, ||), alias command, echo $$ and $?
___
## Authors
* **Mostafa Ehab** - [mostafaehab96](https://github.com/mostafaehab96)
*  **Iman Hamza** - [Imanhamza](https://github.com/Imanhamza)
