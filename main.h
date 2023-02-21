#ifndef _MAIN_H_
#define _MAIN_H_

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"
#include <sys/wait.h>
#include <string.h>

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

list_t *create(char *s);
list_t *add_node(list_t **head, const char *str);
list_t *add_node_end(list_t **head, const char *str);
void free_list(list_t *head);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *search(char *command, list_t **head);
char *_strdup(const char *s);
int _strcmp(char *s1, char *s2);
size_t print_list(const list_t *h);
int count_words(char *s);
void free_arr(char **arr);
char **get_command(char *input);
int execute(char **args, char **argv, char **envp ,list_t **path_list);
void print_error(char *command, char *name);
void exit_func(char **arg);
void env_func(char **arg);
void cd_func(char **arg);
/**
 * struct print - New typedef struct
 * @format: data type
 * @func: a pointer to a function
 */
/*typedef struct builtin
{
	char format;
	int (*func)(va_list arg);
} func_builtin;*/
#endif
