#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void exit_shell(char *arg)
{
	int status = 0;

	if (arg != NULL)
	{
		status = atoi(arg);

		if (status == 0 && strcmp(arg, "0") != 0)
		{
			printf("Error: exit status must be an integer\n");
			exit(1);
		}
	}
	exit(status);
}
