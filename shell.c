#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"
#include <sys/wait.h>
#include <string.h>


int main(int argc, char **argv, char **envp)
{
	char *input = NULL;
	list_t *path_list;
	char *path;
	char *token = NULL;
	char **args = NULL;
	char *copy;

	path = getenv("PATH");
	path_list = NULL;
	path_list = create(path);

	while(1)
	{
		input = read_input();
		/* if EOF */
		if (input == NULL)
			break;
		copy = _strdup(input);
		token = strtok(copy, "\n");
		while (token != NULL)
		{
			args = get_command(token);
			execute(args, argv, envp, &path_list);
			token = strtok(NULL, "\n");
		}
		free(copy);
		free(input);

	}

	free_list(path_list);
	return (0);
}
