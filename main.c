#include "shell.h"

/**
 * main - Entry point to program
 * @argc: Argument count
 * @argv: Argument vector
 * Return: Returns condition
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	char *input, **cmd, **commands;
	int count = 0, i, condition = 1, stat = 0;

	if (argv[1] != NULL)
		read_commands_file(argv[1], argv);
	signal(SIGINT, handle_signal);
	while (condition)
	{
		count++;
		if (isatty(STDIN_FILENO))
			prompt();
		input = _getline();
		if (input[0] == '\0')
			continue;
		save_history(input);
		commands = separate_commands(input);
		for (i = 0; commands[i] != NULL; i++)
		{
			cmd = parse_command(commands[i]);
			if (_strcmp(cmd[0], "exit") == 0)
			{
				free(commands);
				exit_bul(cmd, input, argv, count, stat);
			}
			else if (check_builtin(cmd) == 0)
			{
				stat = handle_builtin(cmd, stat);
				free(cmd);
				continue;
			}
			else
				stat = execute_command(cmd, input, count, argv);
			free(cmd);
		}
		free(input);
		free(commands);
		wait(&stat);
	}
	return (stat);
}
