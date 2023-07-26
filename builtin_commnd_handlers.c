#include "shell.h"

/**
 * check_builtin - Checks if parsed command is a built-in command
 * @cmd: Parsed command to be checked
 * Return: 0 on success, -1 on failure
 */
int check_builtin(char **cmd)
{
	builtin built_ins[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"env", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int i = 0;

	if (*cmd == NULL)
	{
		return (-1);
	}
	while ((built_ins + i)->command)
	{
		if (_strcmp(cmd[0], (built_ins + i)->command) == 0)
			return (0);
		i++;
	}
	return (-1);
}

/**
 * handle_builtin - Handles predefined built in commands
 * @cmd: Array of parsed command strings
 * @st: Status of last execution
 * Return: -1 on failure, 0 on success
 */
int handle_builtin(char **cmd, int st)
{
	builtin built_ins[] = {
		{"cd", change_directory},
		{"env", dis_env},
		{"help", display_help},
		{"echo", execute_echo},
		{"history", display_his},
		{NULL, NULL}
	};
	int i = 0;

	while ((built_ins + i)->command)
	{
		if (_strcmp(cmd[0], (built_ins + i)->command) == 0)
		{
			return ((built_ins + i)->function(cmd, st));
		}
		i++;
	}
	return (-1);
}

/**
 * exit_bul - Exit Status for built-in commands
 * @cmd: Array of parsed command strings
 * @input: Input recieved from user (to be freed)
 * @argv: Arguments before program starts(argv[0] == Shell Program Name)
 * @c: Shell execution count
 * @stat: Exit status
 */
void exit_bul(char **cmd, char *input, char **argv, int c, int stat)
{
	int status, i = 0;

	if (cmd[1] == NULL)
	{
		free(input);
		free(cmd);
		exit(stat);
	}
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) != 0)
		{
			display_illegal_number_error(argv, c, cmd);
			free(input);
			free(cmd);
			exit(2);
		}
		else
		{
			status = _atoi(cmd[1]);
			if (status == 2)
			{
				display_illegal_number_error(argv, c, cmd);
				free(input);
				free(cmd);
				exit(status);
			}
			free(input);
			free(cmd);
			exit(status);

		}
	}
}
