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
	list_t *path_list;
	char *token = NULL, *copy;
	char **args = NULL;
	int should_exit = 0, exit_status = 0, cmd_count = 0;

	check_argc(argc, argv);
	path = _strdup(path);
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
			cmd_count++;
			args = get_command(token);
			should_exit = check_exit(args, argv, &exit_status, cmd_count);
			if (should_exit)
			{
				free_arr(args);
				break;
			}
			execute(args, argv, envp, &path_list, cmd_count);
			token = strtok(NULL, "\n");
		}
		free(copy);
		free(input);
		if (should_exit && exit_status != -1)
			break;
	}
	free_list(path_list);
	free(path);
	if (should_exit)
		exit(exit_status);
	return (0);
}
