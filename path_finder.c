#include "shell.h"

/**
 * path_command -  Search In $PATH for executable command
 * @cmd_name: Name of the command to search for
 * Return: Full path of the command on success, NULL on failure
 */
char *path_command(char *cmd_name)
{
	char *path = _getenv("PATH");
	char *value;
	char *cmd_path;
	struct stat buf;

	value = strtok(path, ":");
	while (value != NULL)
	{
		cmd_path = malloc(_strlen(cmd_name) + _strlen(value) + 2);
		if (!cmd_path)
		{
			perror("Memory allocation failed");
			return NULL;
		}
		_strcpy(cmd_path, value);
		_strcat(cmd_path, "/");
		_strcat(cmd_path, cmd_name);

		if (stat(cmd_path, &buf) == 0)
		{
			free(path);
			return (cmd_path);
		}
		else
		{
			free(cmd_path);
		}
		value = strtok(NULL, ":");
	}
	free(path);
	free(cmd_path);
	return (NULL);
}


/**
 * _getenv - Gets the value of environment variable by name
 * @name: Environment variable name
 * Return: The value of the environment variable or NULL if not found
 */
char *_getenv(const char *name)
{
	size_t name_len;
	size_t value_len;
	char *value;
	int i;

	name_len = _strlen(name);
	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(name, environ[i], name_len) == 0 && environ[i][name_len] == '=')
		{
			value_len = _strlen(environ[i] + name_len + 1);
			value = malloc((value_len + 1) * sizeof(char));
			if (!value)
			{
				perror("Memory allocation failed");
				return (NULL);
			}
			_strncpy(value, environ[i] + name_len + 1, value_len);
			value[value_len] = '\0';
			return (value);
		}
		
	}
	return (NULL);
}
