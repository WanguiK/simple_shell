#include "shell.h"

/**
 * parse_command - Parses the command received from stdin
 * @input: String gathered from stdin
 * Return: Parsed strings to be used as arguments
 */
char **parse_command(char *input)
{
	char **arguments;
	char *argument;
	int i;
	int buffsize = BUFSIZ;

	if (input[0] == ' ' && input[strlen(input)] == ' ')
	{
		exit(0);
	}
	if (input == NULL || strlen(input) == 0)
	{
		return (NULL);
	}
	arguments = malloc(sizeof(char *) * buffsize);
	if (!arguments)
	{
		free(arguments);
		perror("hsh");
		return (NULL);
	}
	argument = strtok(input, "\n\t\r\a ");
	for (i = 0; argument; i++)
	{
		arguments[i] = argument;
		argument = strtok(NULL, "\n\t\r\a ");
	}
	arguments[i] = NULL;

	return (arguments);
}
