#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

/**
 * search - searches for a command in a list of direcotries of the PATH
 * @command: the command to search for
 * @head: the head of the list of directories
 * Return: the full path of the command if found or NULL if not
 */
char *search(char *command, list_t *head)
{
	list_t *current = head;
	char *command_path;

	while (current != NULL)
	{
		command_path = (char *)malloc(_strlen(current->str) + _strlen(command) + 2);
		_strcpy(command_path, current->str);
		_strcat(command_path, "/");
		_strcat(command_path, command);
		if (access(command_path, F_OK) != -1)
			return (command_path);
		free(command_path);
		current = current->next;
	}
	return (NULL);
}

/**
 * count_words - counts words in a string
 * @s: the string to be counted
 * Return: the count
 */

int count_words(char *s)
{
	int i;
	int word_started = 0;
	int count = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] != ' ')
		{
			word_started = 1;
		}
		else if (word_started)
		{
			count++;
			word_started = 0;
		}
	}
	if (word_started)
		count++;
	return (count);
}

/**
 * free_arr - frees an array of strings allocated in heap
 * @arr: the array to be freed
 */
void free_arr(char **arr)
{
	int i = 0;

	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}

	free(arr);
}

/**
 * get_command - accepts a string and split it with space
 * this string should contain a command and it's arguments
 * @input: the string input from the user
 * Return: an array of strings
 * where the first is the command and the rest are arguments, end with NULL
 */
char **get_command(char *input)
{
	int count = count_words(input);
	char *token;
	char **args = (char **) malloc(sizeof(char *) * (count + 2));
	int i = 0;

	token = strtok(input, " ");
	while (token != NULL)
	{
		args[i] = _strdup(token);
		token = strtok(NULL, " ");
		i++;
	}
	args[i] = NULL;

	return (args);
}
