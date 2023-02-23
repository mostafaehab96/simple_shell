#include "main.h"

/**
 * execute - a function to execute the input commands
 * @args: the argument
 * @argv: arguments array
 * @envp: the path of a certain variables
 * @path_list: list of all paths of the variables
 * Return: 0
 */
void execute(char **args, char **argv, char **envp, list_t **path_list)
{
	char *command;
	pid_t pid;
	int status;
	void (*builtin)(char **args);
	char f_letter;

	if (args == NULL)
		return;
	command = search(args[0], path_list);
	f_letter = args[0][0];
	builtin = get_builtin(args[0]);
	if (builtin != NULL)
	{
		builtin(args);
		free(command);
		return;
	}
	if (command != NULL)
	{
		pid = fork();
		if (pid == 0)
		{
			execve(command, args, envp);
			perror("exeve");
			exit(1);
		}
		else
		{
			wait(&status);
			exit_status = WIFEXITED(status) ? WEXITSTATUS(status) : 0;
		}
	}
	else
	{
		fprintf(stderr, "%s: %i: %s: not found\n", argv[0], cmd_count, args[0]);
		exit_status = 127;
	}
	if ((command != NULL) && (f_letter != '/') && (f_letter != '.'))
		free(command);
	free_arr(args);
}

/**
 * read_input - a function to read the input from a file
 * Return: The input of the file or NULL
 */
char *read_input(void)
{
	ssize_t read;
	size_t len;
	char *input = NULL;

	if (isatty(STDIN_FILENO))
	{
		write(1, "$ ", 2);
	}
	read = getline(&input, &len, stdin);

	if (read == -1)
	{
		free(input);
		return (NULL);
	}

	return (input);
}

/**
 * check_argc - checking the argc count and exit if not one
 * @argc: the arguments count
 * @argv: the arguments of the program
 * Return: 0 if not exit
 */
int check_argc(int argc, char **argv)
{
	if (argc != 1)
	{
		fprintf(stderr, "%s: 0: Can't open %s\n", argv[0], argv[1]);
		exit(127);
	}
	return (0);
}
