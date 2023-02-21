#include "main.h"

/**
 * main - a simple shell like program
 * @argc: the arguments count
 * @argv: the arguments of the program
 * @envp: the enviroment variables
 * Return: 0 on Success
 */

int main(int argc, char **argv, char **envp)
{
	char *input = NULL;
	list_t *path_list = NULL;
	char *path = getenv("PATH");
	char *token = NULL;
	char **args = NULL;
	char *copy;
	bool should_exit = 0;
	int exit_status = 0;

	path_list = create(path);
	while (1)
	{
		input = read_input();
		if (input == NULL)
			break;
		copy = _strdup(input);
		token = strtok(copy, "\n");
		while (token != NULL)
		{
			args = get_command(token);
			if (_strcmp(args[0], "exit") == 0)
			{
				should_exit = 1;
				if (args[1] != NULL)
					exit_status = atoi(args[1]);
				free_arr(args);
				break;
			}
			execute(args, argv, envp, &path_list);
			token = strtok(NULL, "\n");
		}
		free(copy);
		free(input);
		if (should_exit)
			break;
	}
	free_list(path_list);
	if (should_exit)
		exit(exit_status);
	return (0);
}
