#include "shell.h"

/**
 * main - entry point for the shell program
 *
 * Return: Always 0 on success
 */
int main(void)
{
    char input[MAX_INPUT_LENGTH];
    pid_t pid;
    int status = 0;

    while (1)
    {
        printf("$ ");
        if (!fgets(input, MAX_INPUT_LENGTH, stdin))
        {
            if (feof(stdin))
            {
                putchar('\n');
                exit(EXIT_SUCCESS);
            }
            else
            {
                perror("fgets");
                exit(EXIT_FAILURE);
            }
        }
        if (input[strlen(input) - 1] == '\n')
            input[strlen(input) - 1] = '\0';

        pid = fork();
        if (pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        if (pid == 0)
        {
            char *args[] = {input, NULL};
            if (execve(input, args, environ) == -1)
            {
                perror("execve");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            if (waitpid(pid, &status, 0) == -1)
            {
                perror("waitpid");
                exit(EXIT_FAILURE);
            }
        }
    }
    return (EXIT_SUCCESS);
}
