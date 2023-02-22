#include "main.h"

/**
 * execute_builtin - Executes a builtin command
 *
 * @arr: An array of arguments
 *
 * Return: 0 on success, 1 on failure
 */

void execute_builtin(char **arr)
{
	if (strcmp(arr[0], "exit") == 0)
		exit_shell(arr[1]);
	else if (strcmp(arr[0], "env") == 0)
		print_env(environ);
	else
	{
		fprintf(stderr, "%s: command not found\n", arr[0]);
	}
}
