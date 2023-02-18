#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	char inp[] = "/bin/ls -l -a /home";
	char **args = get_command(inp);
	int i = 0;

	while (args[i] != NULL)
	{
		printf("%s\n", args[i]);
		i++;
	}

	free_arr(args);

	return (0);
}
