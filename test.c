#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	char *path = getenv("PATH");
	list_t *head = create(path);
	char *command_path;

	print_list(head);
	
	command_path = search("ls", head);
	printf("command path is: %s\n", command_path);

	free_list(head);
	free(command_path);

	return (0);
}
