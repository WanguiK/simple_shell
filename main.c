#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "shell.h"

/**
 * main - Entry point to program
 * @argc: Argument count
 * @argv: Argument vector
 * Return: Returns condition
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	char *input = NULL;

	int stat = 0;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			display_prompt();
		}

		nread = getline(&input, &len, stdin);
		if (nread == -1)
		{
			break;
		}
		if (input[nread - 1] == '\n')
		{
			input[nread - 1] = '\0';
		}
		if (input[0] == '\0')
		{
			continue;
		}
		stat = execute_command(input, argv);
		if (stat == -1)
		{
			perror("Command not found:\n");
		}
		wait(&stat);
		free(input);
	}
	return(stat);
}
