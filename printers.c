#include "shell.h"

/**
 * print_unsigned_integer - Prints unsigned integers using _putchar function
 * @num: Unsigned integer to be printed
 */
void print_unsigned_integer(unsigned int num)
{
	unsigned int x = num;

	if ((x / 10) > 0)
		print_unsigned_integer(x / 10);

	_putchar(x % 10 + '0');
}

/**
 * print_integer - Prints integers using _putchar function
 * @num: Integer to be printed
 */
void print_integer(int num)
{
	unsigned int x = num;

	if (num < 0)
	{
		_putchar('-');
		x = -x;
	}
	if ((x / 10) > 0)
		print_unsigned_integer(x / 10);

	_putchar(x % 10 + '0');
}

/**
 * execute_builtin_echo - Executes built-in echo function
 * @cmd: Parsed Command
 * Return: 0 Upon Success -1 Upon Failure
 */
int execute_builtin_echo(char **cmd)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve("/bin/echo", cmd, environ) == -1)
		{
			return (-1);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		return (-1);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
