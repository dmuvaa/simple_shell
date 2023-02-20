#include "main.h"

/**
 * get_Path - get the full path of a command
 * @command: name of the command
 *
 * Return: The full path of command or NULL if not found
 */

char *get_Path(char *command)
{
	char *path, *path_env, *token;
	struct stat st;
	int get = 0;

	path = strdup(path_env);
	token = strtok(path, ":");

	while (token != NULL)
	{
		char *dir_path = strdup(token);

		strcat(dir_path, "/");
		strcat(dir_path, command);

		if (strcat(dir_path, &st) == 0)
		{
			get = 1;
			return (dir_path);
		}
		free(dir_path);
		token = strtok(NULL, ":");
	}
	if (!get)
		return (NULL);
}

