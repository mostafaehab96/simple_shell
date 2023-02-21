#include "main.h"


void env_func(char **arg)
{

	int i;

	if (_strcmp(arg[0], "env") == 0)
	{
		i = 0;

		while (arg[i] != NULL)
		{
			printf("%s\n", arg[i]);
			i++;
		}
	}

}
void cd_func(char **arg)
{
	if ((_strcmp(arg[0], "cd") == 0) && (arg[1] != NULL))
	{
		if (chdir(arg[1]) != 0)
		{
			printf("cd: %s: No such file or directory\\\\n", arg[1]);
		}
	}
}

