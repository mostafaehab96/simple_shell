#include "main.h"
#include <stdlib.h>
#include <unistd.h>

char *search(char *command, list_t *head)
{
	list_t *current = head;
	char *command_path;

	while(current != NULL)
	{

 		command_path = (char*) malloc(_strlen(current->str) + _strlen(command) + 2);
		_strcpy(command_path, current->str);
		_strcat(command_path, "/");
		_strcat(command_path, command);
		if (access(command_path, F_OK) != -1)
			return command_path;
		free(command_path);
		current = current->next;
	}
	return NULL;
}

