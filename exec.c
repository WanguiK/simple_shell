#include "shell.h"

/**
 * execute_command - Executes commands found in predefined path
 * @argv: Arguments before the program starts
 * @cmd: command
 *
 * Return: 1 Case Command Null, -1 Wrong Command, 0 Command Executed
 */
int execute_command(char *cmd, char **argv)
{
	int status;
	pid_t pid;
	char *environ[] = {NULL};

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
	}
	if (pid == 0)
	{
		if (execve(cmd, argv, environ) == -1)
		{
			perror("Error");
		}
	}
	wait(&status);
	return (status);
}
