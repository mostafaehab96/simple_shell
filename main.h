#ifndef _MAIN_H_
#define _MAIN_H_

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <stdbool.h>

extern char **environ;
extern int cmd_count;
extern int exit_status;

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;
/**
 * struct builtins - New typedef struct
 * @command: the input command
 * @func: a poiner to a function
 */
typedef struct builtins
{
	char *command;
	void (*func)(char **args);
} builtin;

list_t *create(char *s);
list_t *add_node(list_t **head, const char *str);
list_t *add_node_end(list_t **head, const char *str);
void free_list(list_t *head);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strdup(const char *s);
size_t print_list(const list_t *h);
char *search(char *command, list_t **head);
char *_strdup(const char *s);
int _strcmp(char *s1, char *s2);
size_t print_list(const list_t *h);
int count_words(char *s);
void free_arr(char **arr);
char **get_command(char *input);
void execute(char **args, char **argv, char **envp, list_t **path_list);
void print_error(char *command, char *name);
void (*get_builtin(char *command)) (char **args);
char *read_input(void);
void env_func(char **arg);
void cd_func(char **arg);
int check_argc(int argc, char **argv);
int check_exit(char **args, char **argv);
void _setenv(char **args);
void _unsetenv(char **args);
char **tokenize(char *str, const char *delim);
char **tokenize2(char **arr, const char *delim);

#endif
