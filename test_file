#include "main.h"

/**
 * handle_args - Splits a command into an array of arguments
 *
 * @command: The command to split
 * @arr: An array to store the arguments
 *
 * Return: The number of arguments in the array
 */

int handle_args(char *command, char **arr)
{
	char *s_token;
	int i = 0;

	s_token = strtok(command, " \n");
	arr[0] = s_token;

	while (s_token != NULL)
	{
		s_token = strtok(NULL, " \n");
		arr[++i] = s_token;
	}

	return (i);
}

/**
 *  main - Entry point
 *  Return: 0 on success, 1 on failure
 */

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

		my_pid = fork();

		if (my_pid == -1)
		{
			perror("Error");
		}
		else if (my_pid == 0)
		{
			if (execve(arr[0], arr, NULL))
			{
				perror("./shell");
				return (1);
			}
		}
		else
		{
			wait(&status);
		}
		free(arr);
	}
	free(command);
	return (0);
}
