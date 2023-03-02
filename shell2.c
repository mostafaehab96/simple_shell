#include "main.h"

int exit_status = 0;
int cmd_count = 0;

/**
 * main - a simple shell like program
 * @argc: the arguments count
 * @argv: the arguments of the program
 * @envp: the enviroment variables
 * Return: 0 on Success
 */

int main(int argc, char **argv, char **envp)
{
	char *input = NULL, *path = getenv("PATH");
	list_t *path_list;
	char **args = NULL, **lines, **commands;
	int should_exit = 0, i = 0;

	check_argc(argc, argv);
	path = _strdup(path);
	path_list = create(path);
	while (1)
	{
		input = read_input();
		if (input == NULL)
			break;
		lines = tokenize(input, "\n");
		commands = tokenize2(lines, ";");
		cmd_count++;
		for (i = 0; commands[i] != NULL; i++)
		{
			args = get_command(commands[i]);
			should_exit = check_exit(args, argv);
			if (should_exit == 1 || should_exit == -1)
			{
				free_arr(args);
				continue;
			}
			execute(args, argv, envp, &path_list);
		}
		cmd_count += i;
		free(input);
		free_arr(lines);
		free_arr(commands);
		if (should_exit == 1)
			break;
	}
	free_list(path_list);
	free(path);
	if (should_exit || exit_status != 0)
		exit(exit_status);
	return (0);
}
