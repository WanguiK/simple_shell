#include "shell.h"

/**
 * execute_command - Excutes commands found in predefined path
 * @cmd: Array of parsed command strings
 * @input: Input recieved from user (to be freed)
 * @counter:Shell Excution Time Case of Command Not Found
 * @argv: Arguments before program starts(argv[0] == Shell Program Name)
 * Return: 1 Case Command Null -1 Wrong Command 0 Command Excuted
 */
int execute_command(char **cmd, char *input, int counter, char **argv)
{
	int wstatus;
	pid_t pid;

	if (*cmd == NULL)
		return (EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}
	if (pid == 0)
	{
		if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
			path_command(cmd);
		if (access(cmd[0], R_OK) != 0)
		{
			display_error_message(cmd[0], counter, argv);
			free_all_memory(cmd, input);
			exit(127);
		}
		if (execve(*cmd, cmd, environ) == -1)
			return (2);
		else
			return (0);
	}
	wait(&wstatus);
	if (WIFEXITED(wstatus))
	{
		if (WEXITSTATUS(wstatus) == 0)
			return (0);
		else if (WEXITSTATUS(wstatus) == 2)
			return (2);
		else if (WEXITSTATUS(wstatus) == 127)
			return (127);
	}
	return (127);
}

/**
 * handle_signal - Configures ^C not to terminate our shell
 * @sig: Incoming Signal
 */
void handle_signal(int sig)
{
	if (sig == SIGINT)
	{
		PRINT("\n$ ");
	}
}
