#include "shell.h"

/**
 * execute_command - Executes commands found in predefined path
 * @input: Input received from the user (to be freed)
 * @counter: Shell Execution Time Case of Command Not Found
 * @argv: Arguments before the program starts (argv[0] == Shell Program Name)
 * Return: 1 Case Command Null, -1 Wrong Command, 0 Command Executed
 */
int execute_command(char *input, char **argv)
{
	int status;
	pid_t pid;
	char *environ[] = {NULL};

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (0);
	}
	if (pid == 0)
	{
		if (access(input, X_OK) == -1)
		{
			perror("Error: Command not found:\n");
		}
		if (execve(input, argv, environ) == -1)
		{
			perror("Error");
			exit(1);
		}
	}
	wait(&status);
	return(status);
}
