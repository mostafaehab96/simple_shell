#include "main.h"

/**
 * get_builtin - a function to get the correct command to execute
 * @command: the input command
 * @*args: arguments of the command
 * Return: the right function or NULL
 */

void (*get_builtin(char *command)) (char **args)
{
	int i;
	builtin list[] = {
		{"env", env_func},
		{"cd", cd_func},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{NULL, NULL}
	};

	for (i = 0; list[i].command != NULL; i++)
	{
		if (_strcmp(list[i].command, command) == 0)
			return (list[i].func);
	}

	return (NULL);
}
