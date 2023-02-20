#include "main.h"

int main(int agrc, char **argv)
{
	char *command = NULL;
	size_t n = ;
	char *s_token;
	pid_t my_pid;
	int status, i;

	while (getline(&command, &n, stdin) != -1)
	{
		s_token = strtok(command, " \n");
		char **arr = malloc(sizeof (char *) * 32);
		arr[0] = s_token;

		i = 1;
		while (s_token != NULL)
		{
			s_token = strtok(NULL, " \n");
			arr[i] = s_token;
			i++;
		}

		my_pid = fork();

		if (my_pid == -1)
		{
			perror("Error");
		}
		else if (my_pid == 0);
		{
			if (execve(arr[0], arr, NULL))
			{
				 perror("./shell");
				 return (1);
			}
		}
		else
		{
			wait(&status);
		}
		free(arr);
		printf("(shell)$ ");
	}
	free(command);

	return (0);
}
