#include "main.h"
#include <string.h>


void (*get_builtin(char *command)) (char **args)
{
	int i;
	builtin list[] = {
		{"env", env_func},
		{"exit", exit_func},
		{NULL, NULL}
	};
	
	for (i = 0; list[i].command != NULL; i++)
	{
		if (strcmp(list[i].command, command) == 0)
			return (list[i].func);
	}

	return (NULL);
	
}
