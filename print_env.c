#include "main.h"

/**
 * print_env - Prints the current environment
 */

void print_env(void)
{
	int i = 0;
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
}