#include "main.h"

extern int cmd_count;
extern int exit_status;

/**
 * execute - a function to execute the input commands
 * @args: the argument
 * @argv: arguments array
 * @envp: the path of a certain variables
 * @path_list: list of all paths of the variables
 * @cmd_count: the commands count used in shell for printing errors
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
		free(command);
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
		fprintf(stderr, "%s: %i: %s: not found\n", argv[0], cmd_count, args[0]);
	}
	if ((command != NULL) && (args[0][0] != '/'))
		free(command);
	free_arr(args);

	return (err);

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
