#include "main.h"

/**
 * execute_command - Executes the command entered by the user
 * @arr: an array of arguments
 * @env: an array of environment variables
 *
 * Return: 0 on success, 1 on failure
 */

int execute_command(char **arr, char **env)
{
	pid_t child_pid;
	char *path = NULL;
	int status;

	if (arr[0] == NULL)
		return (0);

	path = get_path(arr[0], envp);
	if (path == NULL)
	{
		fprintf(stderr, "%s: command not found\n", arr[0]);
		return (1);
	}

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error");
		return (1);
	}
	else if (child_pid == 0)
	{
		if (execve(path, arr, envp) == -1)
		{
			perror("Error");
			return (1);
		}
	}
	else
	{
		wait(&status);
	}
	free(path);
	return (0);
}
