#include "main.h"

int main(int argc, char **argv)
{
	char *prompt = "(shell)$ ";
	char *linep;
	size_t n = 0;

	while(1)
	{
		printf("%s", prompt);
		getline(&linep, &n, stdin);
		printf("%s\n", linep);
	}
	free(linep);

	return (0);
}
