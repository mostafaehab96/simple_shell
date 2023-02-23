#include "main.h"

/**
 * env_func - a function to stimulate the env command
 * @arg: arguments
 * Return: Nothing
 */
void env_func(char **arg)
{
	int i;

	if (arg[1] != NULL)
		fprintf(stderr, "env: %s: No such file or directory\n", arg[1]);
	else if (strcmp(arg[0], "env") == 0)
	{
		for (i = 0; environ[i] != NULL; i++)
		{
			printf("%s\n", environ[i]);
		}
	}

	free_arr(arg);

}
/**
 * cd_func - a function to stimulate the cd command
 * @args: arguments
 * Return: Nothing
 */
void cd_func(char **args)
{
	char *dir = args[1];
	char *home = getenv("HOME");
	char *old = getenv("OLDPWD");
	char current[256];

	getcwd(current, sizeof(current));
	if (dir == NULL)
	{
		setenv("OLDPWD", current, 1);
		chdir(home);
		setenv("PWD", home, 1);
	}
	else if (_strcmp(dir, "-") == 0)
	{
		chdir(old);
		setenv("PWD", old, 1);
		setenv("OLDPWD", current, 1);
		getcwd(current, sizeof(current));
		printf("%s\n", current);
	}
	else
	{
		if (chdir(dir) != 0)
			fprintf(stderr, "sh: %i: cd: can't cd to %s\n", cmd_count, dir);
		else
		{
			setenv("OLDPWD", current, 1);
			setenv("PWD", dir, 1);
		}
	}


	free_arr(args);
}


/**
 * check_exit - checks for exit command and exit status
 * @args: the arguments passed as input
 * @argv: the arguments of main (name of the program)
 * Return: 1 if should exit or 0 if not
 */
int check_exit(char **args, char **argv)
{
	char *first;
	char *second;
	int i;

	if (args == NULL)
		return (0);
	first = args[0];
	second = args[1];
	exit_status = 0;
	if (_strcmp(first, "exit") == 0)
	{
		if (second != NULL)
		{
			for (i = 0; second[i] != '\0'; i++)
			{
				if (second[i] < '0' || second[i] > '9')
				{
					fprintf(stderr, "%s: %i: exit: Illegal number: %s\n",
						argv[0], cmd_count, second);
					exit_status = -1;
					return (1);
				}
			}
			exit_status = atoi(second);
		}

		return (1);
	}

	return (0);
}

/**
 * _setenv - sets an environment variable
 * @args: the array of arguments passed as input
 */
void _setenv(char **args)
{
	char *variable = args[1];
	char *value;
	int result = 0;

	if (variable != NULL)
	{
		value = args[2];
		if (value == NULL)
			fprintf(stderr, "Error setting the variable\n");
		else
			result = setenv(variable, value, 1);
	}
	else
		fprintf(stderr, "Error setting the variable\n");

	if (result == -1)
		fprintf(stderr, "Error setting the variable\n");
	free_arr(args);
}

/**
 * _unsetenv - deletes an environment variable
 * @args: the array of arguments passed as input
 */
void _unsetenv(char **args)
{
	char *variable = args[1];
	int result;

	result = unsetenv(variable);
	if (result == -1)
		fprintf(stderr, "Error unsetting the variable\n");

	free_arr(args);
}

