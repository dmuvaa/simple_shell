#include "main.h"

/**
 * check_builtins - Checks if a command is a builtin
 *
 * @command: The command to check
 *
 * Return: 1 if a builtin, 0 otherwise
 */

int check_builtins(char *command)
{
	if (strcmp(command, "exit") == 0)
		return (1);
	if (strcmp(command, "env") == 0)
		return (1);
	return (0);
}
