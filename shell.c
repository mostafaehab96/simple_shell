#include <stdio.h>
#include <unistdlib.h>
#include <stlib.h>



int main(int argc, char **argv, char **env)
{
	char *command;
	size_t len;
	ssize_t read = 1;
	int status;
	pid_t pid;
	int error;

	while(read)
	{
		write(1, "$ ", 2);
		command = getline(&command, &len, stdin);


		if (command == NULL || read = -1)
			break;

	}

	write(1, "exit\n", 5);

	return (0);
}
