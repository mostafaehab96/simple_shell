#include "main.h"

void exit_func(va_list arg)
{
	char *s = va_arg(args, char *);

	if (_strcmp(s) == 'exit')
		exit(0);
	else
		continue;
}

void env_func(va_list arg)
{
	char *args;

	while ((args = va_arg(arg, char *)) != NULL)
		printf("%s\\\\n", arg);
}
