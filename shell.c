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
	char *path = getenv("PATH");
	int checking_argc = check_argc(argc, argv);
	list_t *path_list = create(path);
	char *token = NULL;
	char **args = NULL;
	char *copy;
	bool should_exit = 0;
	int exit_status = 0;

	while (checking_argc == 0)
	{
		input = read_input();
		if (input == NULL)
			break;
		copy = _strdup(input);
		token = strtok(copy, "\n");
		while (token != NULL)
		{
			args = get_command(token);
			should_exit = check_exit(args, argv, &exit_status);
			if (should_exit)
			{
				free_arr(args);
				break;
			}
			execute(args, argv, envp, &path_list);
			token = strtok(NULL, "\n");
		}
		free(copy);
		free(input);
		if (should_exit && exit_status != -1)
			break;
	}
	free_list(path_list);
	if (should_exit)
		exit(exit_status);
	return (0);
}
