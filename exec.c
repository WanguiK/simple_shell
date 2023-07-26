#include "shell.h"

/**
 * execute_command - Executes commands found in predefined path
 * @argv: Arguments before the program starts
 * @cmd: command
 *
 * Return: 1 Case Command Null, -1 Wrong Command, 0 Command Executed
 */
int execute_command(char **cmd,  char **argv)
{
	int status;
	pid_t pid;
	char *environ[] = {NULL};
	struct stat buf;
	char *full_cmd_path = NULL;

	if (cmd == NULL || cmd[0] == NULL)
		return (EXIT_FAILURE);
	if (_strcmp(cmd[0], "exit") == 0)
		exit(EXIT_SUCCESS);
	if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
	{
		full_cmd_path = path_command(cmd[0]);
		if (full_cmd_path == NULL)
			perror("Command not found:\n");
		if (access(full_cmd_path, X_OK) == -1)
		{
			perror("Error: Command not found:\n");
			free(full_cmd_path);
		}
		free(cmd[0]);
		cmd[0] = full_cmd_path;
	}
	if (stat(cmd[0], &buf) == -1)
	{
		perror("Command not found:\n");
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Error");
	}
	if (pid == 0)
	{
		if (execve(cmd[0], argv, environ) == -1)
		{
			perror("Error");
		}
	}
	wait(&status);
	return (status);
}
