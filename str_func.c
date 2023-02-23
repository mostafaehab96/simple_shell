#include "main.h"


/**
 * _strlen - returns the length of a string
 * @s: the string
 * Return: length
 */

int _strlen(char *s)
{
	int length = 0,
	    i;

	if (s == NULL)
	{
		printf("NULL\n");
		return (0);
	}
	for (i = 0; s[i] != '\0'; i++)
	{
		length++;
	}
	return (length);
}

/**
 * *_strcpy - copies the string pointed to by src
 * including the terminating null byte (\0)
 * to the buffer pointed to by dest
 * @dest: the return value
 * @src: source
 * Return:dest
 */
char *_strcpy(char *dest, char *src)
{
	int size1 = _strlen(src),
	    i;
	for (i = 0; i < size1; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * *_strcat - concatenates two strings
 * @dest: first string
 * @src: second string
 * Return: dest
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	while (1)
	{
		if (dest[i] == '\0')
		{
			while (src[j] != '\0')
			{
				dest[i] = src[j];
				j++;
				i++;
			}
			break;
		}
		i++;
	}

	dest[i] = '\0';

	return (dest);
}

/**
 * *_strdup -  a function that returns a pointer to
 * a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @s : pointer to the new str
 * Return: NULL or a pointer to the duplicated string
 */
char *_strdup(const char *s)
{
	int len;
	char *new;
	int i;

	if (s == NULL)
		return (NULL);

	len = _strlen((char *) s);
	new = malloc(sizeof(char) * len + 1);

	if (new == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		new[i] = s[i];

	new[i] = '\0';

	return (new);
}

/**
 * _strcmp - compares two strings
 * @s1: first string to compare
 * @s2: second string to compare
 *
 * Return: 0 if two strings are the same
 * int less than 1 if s1 comes before s2
 * int bigger than 1 if s1 comes after s2
 */


int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] == '\0' && s2[i] != '\0')
			return (-1);
		if (s2[i] == '\0' && s1[i] != '\0')
			return (1);

		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}

		i++;
	}

	return (0);
}
