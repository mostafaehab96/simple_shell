#include "main.h"
#include <stdlib.h>
#include <stdio.h>


/* _strlen function */
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

/* _strcpy function */
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

/*_strcat function */
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

/*_strdup function */
char *_strdup(const char *s)
{
	int len = _strlen((char *) s);
	char *new = malloc(sizeof(char) * len + 1);
	int i;

	if (new == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		new[i] = s[i];

	new[i] = '\0';

	return (new);
}
/**
 * _strcmp - compares two strings.
 * @s1: first string
 * @s2: second string
 * Return: integer
 */

int _strcmp(char *s1, char *s2)
{
	int i;
	int diff = 0;

	for (i = 0; s1[i] && s2[i]; i++)
	{

		if (s1[i] != s2[i])
		{
			diff = s1[i] - s2[i];
			break;
		}
		else
		{
			diff = s1[i] - s2[i];
		}
	}
	return (diff);
}
