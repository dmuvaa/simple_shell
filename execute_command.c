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

	path = get_path(arr[0], env);
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
		if (execve(path, arr, env) == -1)
		{
			perror("Error");
			free(path);
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

/**
 * get_path - Searches for the command in the PATH
 * environment variable
 * @command: the command to search for
 * @env: an array of environment variables
 *
 * Return: The full path of the command or NULL
 * if not found
 */

char *get_path(char *command, char **env)
{
	char *path_env, *path, *dir, *tmp;
	struct stat st;

	path_env = get_env_var("PATH", env);

	if (path_env == NULL)
		return (NULL);

	path = strdup(path_env);
	if (path == NULL)
		return (NULL);

	dir = strtok(path, ":");
	while (dir != NULL)
	{
		tmp = strcat(dir, "/");
		tmp = strcat(tmp, command);
		if (stat(tmp, &st) == 0)
		{
			free(path_env);
			free(path);
			return (tmp);
		}
		free(tmp);
		dir = strtok(NULL, ":");
	}
	free(tmp);
	dir = strtok(NULL, ":");

	free(path_env);
	free(path);

	return (NULL);
}

