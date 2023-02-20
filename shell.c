#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"
#include <sys/wait.h>
#include <string.h>


int main(void)
{
	char *input;
	char *command;
	list_t *path_list;
	char *path;
	size_t len;
	ssize_t read = 1;
	int status;
	pid_t pid;
	char *token = NULL;
	char **args;


	path = getenv("PATH");
	path_list = NULL;
	path_list = create(path);
	print_list(path_list);

	while(read)
	{
		write(1, "$ ", 2);
		read = getline(&input, &len, stdin);
		/* if EOF */
		if (input == NULL || read == -1)
			break;
		printf("%s\n", input);	
		token = strtok(input, "\n");
		while (token != NULL)
		{
			args = get_command(token);
			if ((command = search(args[0], &path_list)) != NULL)
			{
				pid = fork();
				if (pid == 0)
					execve(command, args, NULL);
				else
					wait(&status);
			}
			else
				perror("Command Not Found");

			token = strtok(NULL, "\n");
		}
		

	}

	free_list(path_list);

	write(1, "exit\n", 5);

	return (0);
}
