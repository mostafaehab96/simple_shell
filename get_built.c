#include "main.h"


void (*get_builtin(char *command)) (char **args)
{
	int i;
	builtin list[] = {
		{"env", env_func},
		{"cd", cd_func},
		{NULL, NULL}
	};
	
	for (i = 0; list[i].command != NULL; i++)
	{
		if (_strcmp(list[i].command, command) == 0)
			return (list[i].func);
	}

	return (NULL);
	
}
