#include "shell.h"

/**
 * create_environment_array - Creates an array of Enviroment Variables
 * @env_array: Array to store Environment Variables
 */

void create_environment_array(char **env_array)
{
	int i;

	for (i = 0; environ[i]; i++)
		env_array[i] = _strdup(environ[i]);
	env_array[i] = NULL;
}

/**
 * free_environment_array - Frees the memory
 * @env_array: Array of Environment Variables
 */
void free_environment_array(char **env_array)
{
	int i;

	for (i = 0; env_array[i]; i++)
	{
		free(env_array[i]);
	}
}
