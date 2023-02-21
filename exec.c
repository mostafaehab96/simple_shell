#include "main.h"

int execute(char **args, char **argv, char **envp ,list_t **path_list)
{
	char *command;
	int err = 0;
	pid_t pid;
	int status;
	void (*builtin) (char **args);

	builtin = get_builtin(args[0]);
	if (builtin != NULL)
	{
		builtin(args);
		return (0);
	}


	if ((command = search(args[0], path_list)) != NULL)
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

        if (command != NULL && args[0][0] != '/')
		free(command);
	free_arr(args);

	return (err);

}


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
