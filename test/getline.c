#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

char *my_getline(void);

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL;

	while ((line = my_getline()) != NULL)
	{
		printf("You entered: %s\n", line);
		free(line);
	}
	return (0);
}

/**
 * my_getline - a getline function
 *
 * Return: A getline function
 */
char *my_getline(void)
{
	static char buffer[BUFFER_SIZE];
	static int buffer_pos;
	static int buffer_len;

	if (buffer_pos >= buffer_len)
	{
		buffer_len = read(STDIN_FILENO, buffer, BUFFER_SIZE);
		buffer_pos = 0;
	}

	if (buffer_len == 0)
	{
		return (NULL);
	}

	int i;

	for (i = buffer_pos; i < buffer_len; i++)
	{
		if (buffer[i] == '\n')
		{
			break;
		}
	}

	char *line = (char *) malloc((i - buffer_pos + 1) * sizeof(char));

	for (int j = buffer_pos; j < i; j++)
	{
		line[j - buffer_pos] = buffer[j]
	}
	line[i - buffer_pos] = '\0';

	buffer_pos = i + 1;

	return (line);
}
