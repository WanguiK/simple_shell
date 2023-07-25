#include "shell.h"

/**
 *_strlen- returns the length of a string
 *@s: character to return the length
 *
 *Return: 0 Always
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}
