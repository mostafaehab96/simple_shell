#include "main.h"


/**
 * tokenize - splits a string with a delimeter using strtok
 * @str: the string to be splitted
 * @delim: the delimeter
 * Return: an array of splitted words
 */

char **tokenize(char *str, const char *delim)
{
	char **words = NULL;
	int size = 0, i = 0;
	char *copy = NULL, *token = NULL;

	if (str == NULL)
		return (NULL);

	words = (char **) malloc(sizeof(char *) * 10);
	if (words == NULL)
		return (NULL);

	copy = _strdup(str);
	token = strtok(copy, delim);
	while (token != NULL)
	{
		size++;
		if (size > 9)
			words = (char **) realloc(words, sizeof(char *) * (size + 1));
		words[i] = _strdup(token);
		i++;
		token = strtok(NULL, delim);
	}
	words = realloc(words, sizeof(char *) * (size + 1));
	words[i] = NULL;
	free(copy);
	return (words);
}

/**
 * tokenize2 - splits and array of strings with a delimeter using strtok
 * @arr: the array to be splitted
 * @delim: the delimeter
 * Return: the splitted array of strings
 */

char **tokenize2(char **arr, const char *delim)
{
	int size = 0, j = 0, i;
	char *copy = NULL, *token = NULL;
	char **words;

	if (arr == NULL)
		return (NULL);
	words = (char **) malloc(sizeof(char *) * 10);
	if (words == NULL)
		return (NULL);

	for (i = 0; arr[i] != NULL; i++)
	{
		copy = _strdup(arr[i]);
		token = strtok(copy, delim);
		while (token != NULL)
		{
			size++;
			if (size > 9)
				words = (char **) realloc(words, sizeof(char *) * (size + 1));
			words[j] = _strdup(token);
			token = strtok(NULL, delim);
			j++;
		}
		free(copy);
	}
	words = realloc(words, sizeof(char *) * (size + 1));
	words[j] = NULL;

	return (words);
}
