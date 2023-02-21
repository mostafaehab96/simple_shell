#include "main.h"
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int execute(char **args, char **argv, char **envp ,list_t **path_list)
{
	char *command;
	int err = 0;
	pid_t pid;
	int status;

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
		perror(argv[0]);
		perror("Not found");
	}

        if (command != NULL && args[0][0] != '/')
		free(command);
	free_arr(args);

	return (err);

}


