#include "main.h"

/**
 * env_func - a function to stimulate the env command
 * @arg: arguments
 * Return: Nothing
 */
void env_func(char **arg)
{
	int i;

	if (strcmp(arg[0], "env") == 0)
	{
		for (i = 0; environ[i] != NULL; i++)
		{
			printf("%s\n", environ[i]);
		}
	}

}
/**
 * cd_func - a function to stimulate the cd command
 * @arg: arguments
 * Return: Nothing
 */
void cd_func(char **arg)
{
	if ((_strcmp(arg[0], "cd") == 0) && (arg[1] != NULL))
	{
		if (chdir(arg[1]) != 0)
		{
			printf("cd: %s: No such file or directory\n", arg[1]);
		}
	}
}

