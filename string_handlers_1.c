#include "shell.h"

/**
 * _putchar - Writes the character to stdout
 *
 * @c: Character to print
 *
 * Return: character written to standard output
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - Prints a string
 *
 * @str: pointer to string
 *
 * Return: Void
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}

/**
 * _strncpy - Copies a string
 *
 * @dest: Destination string
 *
 * @src: Source string
 * @num: number to be copied
 *
 * Return: Pointer to the destination string
 */
char *_strncpy(char *dest, char *src, int num)
{
	int i = 0;

	while (i < num && *(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	while (i < num)
	{
		*(dest + i) = '\0';
		i++;
	}
	return (dest);
}

/**
 * _strlen - Computes the length of a string
 *
 * @s: Input string
 *
 * Return: length of string
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		continue;
	}
	return (i);
}

/**
 * _atoi - Convert string to a integer
 *
 * @s: Input Strings
 *
 * Return: The converted integer
 */
int _atoi(char *s)
{
	int i = 0, j = 1, k;
	unsigned int l = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			return (2);
		}
		k = s[i] - '0';

		if (l > 0 && !(k >= 0 && k <= 9))
			break;

		if (k >= 0 && k <= 9)
			l = l * 10 + k;

		i++;
	}
	l *= j;
	return (l);
}
