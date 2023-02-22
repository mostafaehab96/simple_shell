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


/**
 * check_exit - checks for exit command and exit status
 * @args: the arguments passed as input
 * @argv: the arguments of main (name of the program)
 * @exit_status: the exit status to be changed
 * Return: 1 if should exit or 0 if not
 */
int check_exit(char **args, char **argv, int *exit_status)
{
	char *first = args[0];
	char *second = args[1];
	int i;

	*exit_status = 0;
	if (_strcmp(first, "exit") == 0)
	{
		if (second != NULL)
		{
			for (i = 0; second[i] != '\0'; i++)
			{
				if (second[i] < '0' || second[i] > '9')
				{
					fprintf(stderr, "%s: 1: exit: Illegal number: %s\n", argv[0], second);
					*exit_status = -1;
					return (1);
				}
			}
			*exit_status = atoi(second);
		}

		return (1);
	}

	return (0);
}
