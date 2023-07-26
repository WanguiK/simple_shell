#include "shell.h"

/**
 * display_error_message - Displays an error message for a command not found
 * @input: Input recieved from the user
 * @counter: Count of shell loop
 * @argv: Arguments before program starts(argv[0] == Shell Program Name)
 */

void display_error_message(char *input, int counter, char **argv)
{
	char *counter_str;

	PRINT(argv[0]);
	PRINT(": ");
	counter_str = _itoa(counter);
	PRINT(counter_str);
	free(counter_str);
	PRINT(": ");
	PRINT(input);
	PRINT(": command not found\n");
}

/**
 * display_illegal_number_error - Prints a custom error for an illegal number
 * @argv: Arguments before program starts(argv[0] == Shell Program Name)
 * @error_count: Error Count
 * @cmd: Array of parsed command strings
 */

void display_illegal_number_error(char **argv, int error_count, char **cmd)
{
	char *error_count_str = _itoa(error_count);

	PRINT(argv[0]);
	PRINT(": ");
	PRINT(error_count_str);
	PRINT(": ");
	PRINT(cmd[0]);
	PRINT(": Illegal number: ");
	PRINT(cmd[1]);
	PRINT("\n");
	free(error_count_str);
}

/**
 * display_file_error - Prints a custom error when a file cannot be opened
 * @argv: Arguments before program starts(argv[0] == Shell Program Name)
 * @error_count: Error Count
 */
void display_file_error(char **argv, int error_count)
{
	char *error_count_str = _itoa(error_count);

	PRINT(argv[0]);
	PRINT(": ");
	PRINT(error_count_str);
	PRINT(": Can't open ");
	PRINT(argv[1]);
	PRINT("\n");
	free(error_count_str);
}
