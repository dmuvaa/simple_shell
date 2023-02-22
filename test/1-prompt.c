#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	char *command = NULL;
	size_t n = 0;
	pid_t my_pid;
	int status;

	while (1)
	{
		printf("(shell)$ ");

		if (getline(&command, &n, stdin) == -1)
			break;

		char **arr = malloc(sizeof(char *) * 32);
		int argc = handle_args(command, arr);

		if (strcmp(arr[0], "exit") == 0)
		{
			free(command);
			free(arr);
			exit(0);
		}
