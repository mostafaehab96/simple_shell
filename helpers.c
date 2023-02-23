#include "main.h"

/**
 * search - searches for a command in a list of direcotries of the PATH
 * @command: the command to search for
 * @head: the head of the list of directories
 * Return: the full path of the command if found or NULL if not
 */
char *search(char *command, list_t **head)
{
	list_t *current = NULL;
	char *command_path = NULL;
	int command_len = _strlen(command);
	int path_len;

	if (command == NULL)
		return (NULL);
	if (command[0] == '/')
	{
		if (access(command, X_OK) != -1)
			return (command);
		return (NULL);
	}
	else if (command[0] == '.')
		return (command);
	if (head == NULL)
		return (NULL);
	current = *head;
	while (current != NULL)
	{
		path_len = current->len;
		command_path = (char *) malloc(sizeof(char) * path_len + command_len + 2);
		_strcpy(command_path, current->str);
		strcat(command_path, "/");
		strcat(command_path, command);
		if (access(command_path, X_OK) != -1)
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

	if (arr == NULL)
		return;

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
	char **args;
	int i = 0;

	if (count > 0)
		args = (char **) malloc(sizeof(char *) * (count + 1));
	else
		return (NULL);
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
