#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, 1 on failure
 */

int main(void)
{
	char *command = NULL;
	size_t n = 0;

	while (1)
	{
		char **arr = malloc(sizeof(char *) * 32);

		printf("(shell)$ ");

		if (getline(&command, &n, stdin) == -1)
			break;

		if (handle_args(command, arr) == 0)
		{
			free(arr);
			continue;
		}

		if (check_builtins(arr[0]))
		{
			execute_builtin(arr);
		}
		else
		{
			execute_command(arr, environ);
		}
		free(arr);
	}
	free(command);
	return (0);

}
