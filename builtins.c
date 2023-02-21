#include "main.h"

extern char **environ;

void env_func(char **arg)
{

	int i;
	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}

}
void cd_func(char **arg)
{
	if ((_strcmp(arg[0], "cd") == 0) && (arg[1] != NULL))
	{
		if (chdir(arg[1]) != 0)
		{
			printf("cd: %s: No such file or directory\n", arg[1]);
		}
	}
}

