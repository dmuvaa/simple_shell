#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, 1 on failure
 */

int main(int argc, char *argv[], char *envp[])
{
	char *command = NULL;
	size_t n = 0;
	pid_t my_pid;
	int status;

	(void)argc;
	(void)argv;
	env = envp;

	while (1)
	{
		printf("(shell)$ ");
		if (getline(&command, &n, stdin) == -1)
			break;

		char **arr = malloc(sizeof(char *) * 32);
		int argc = handle_args(command, arr);
		if (argc == 0)
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
			execute_command(arr);
		}
		free(arr);
	}
	free(command);
	return (0);
}
