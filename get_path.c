#include "main.h"

/**
 * get_path - Searches the PATH for the given
 * command
 * @command: The command to search for
 *
 * Return: The full path of the command found,
 * NULL otherwise
 */

char *get_path(char *command, char **env)
{
	char *path, *tok, *tmp, *path_cpy;
	struct st;

	path = _getenv("PATH", env);
	if (path == NULL)
		return (NULL);

	path_cpy = _strdup(path);
	if (path_cpy == NULL)
	{
		free(path);
		return (NULL);
	}
	tok = strtok(path_cpy,":");
	while (tok != NULL)
	{
		tmp = _strcat(tok, "/");
		tmp = _strcat(tmp, command);
		if (stat(tmp, &st) == 0)
		{
			free(path);
			free(path_cpy);
			return (tmp);
		}
		free(tmp);
		tok = strtok(NULL, ":");
	}
	free(path);
	free(path_cpy);
	return (NULL);
}

