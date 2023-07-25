#include "shell.h"

/**
 * parse_command - Parses the command received from stdin
 * @input: String gathered from stdin
 * Return: Parsed strings to be used as arguments
 */
char **parse_command(char *input)
{
	char **tokens = 0;
	char *argv;
	int i;
	int buffsize = BUFSIZ;
	const char *delim = " ";

	if (input[0] == ' ' && input[_strlen(input)] == ' ')
	{
		return (NULL);
	}
	if (input == NULL || _strlen(input) == 0)
	{
		return (NULL);
	}
	argv = malloc(sizeof(char *) * buffsize);
	if (!tokens)
	{
		free(tokens);
		perror("hsh");
		return (NULL);
	}
	argv = strtok(input, delim);
	for (i = 0; argv; i++)
	{
		tokens[i] = argv;
		argv = strtok(NULL, delim);
	}
	tokens[i] = NULL;

	return (tokens);
}
