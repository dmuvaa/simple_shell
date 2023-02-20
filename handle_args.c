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
