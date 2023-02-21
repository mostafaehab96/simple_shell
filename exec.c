#include "main.h"

/**
 * execute - a function to execute the input commands
 * @args: the argument
 * @argv: arguments array
 * @envp: the path of a certain variables
 * @path_list: list of all paths of the variables
 * Return: 0
 */
int execute(char **args, char **argv, char **envp, list_t **path_list)
{
	char *command = search(args[0], path_list);
	int err = 0;
	pid_t pid;
	int status;
	void (*builtin)(char **args);

	builtin = get_builtin(args[0]);
	if (builtin != NULL)
	{
		builtin(args);
		return (0);
	}


	if (command != NULL)
	{
		pid = fork();
		if (pid == 0)
		{
			err = execve(command, args, envp);
			perror("exeve");
		}
		else if (pid == -1)
			perror("Pid error");
		else
			wait(&status);
	}
	else
	{
		print_error(args[0], argv[0]);
	}
	if ((command != NULL) && (args[0][0] != '/'))
		free(command);
	free_arr(args);

	return (err);

}

/**
 * print_error - a function to print the error message
 * @command: the input command
 * @name: the name of the name of the command
 * Return: Nothing
 */
void print_error(char *command, char *name)
{
	int com_len = _strlen(command);
	int name_len = _strlen(name);
	char *error = malloc(sizeof(char) * com_len + name_len + 20);

	if (error == NULL)
		return;

	_strcat(error, name);
	_strcat(error, ": 1: ");
	_strcat(error, command);
	_strcat(error, ": not found\n");

	write(2, error, _strlen(error));

	free(error);
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
