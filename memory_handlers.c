#include "shell.h"

/**
 * custom_realloc -  Reallocates a memory block using malloc and free
 * @old_size: previous Size Of The Pointer
 * @ptr: Pointer
 * @new_size: new size of the pointer
 * Return: Pointer to reallocated memory
 */
void *custom_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *result;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	result = malloc(new_size);
	if (result == NULL)
	{
		free(result);
		return (NULL);
	}
	if (ptr == NULL)
	{
		fill_array_with_char(result, '\0', new_size);
		free(ptr);
	}
	else
	{
		copy_memory(result, ptr, old_size);
		free(ptr);
	}
	return (result);
}

/**
 * free_all_memory - free memory allocated
 * @cmd: array pointer
 * @line: char pointer
 * Return: Void
 */
void free_all_memory(char **cmd, char *line)
{
	free(cmd);
	free(line);
	cmd = NULL;
	line = NULL;
}

/**
 * copy_memory - copy bytes of memory from source to destination
 *@dest: destination pointer
 *@src: source pointer
 *@n: size to be copied
 *Return: pointer to destination
 */
char *copy_memory(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
 * fill_array_with_char - fill an array by constant byte
 *@a: void pointer
 *@el: int
 *@len: length for int
 *Return: void pointer
 */
void *fill_array_with_char(void *a, int el, unsigned int len)
{
	char *p = a;
	unsigned int i = 0;

	while (i < len)
	{
		*p = el;
		p++;
		i++;
	}
	return (a);
}

/**
 * custom_calloc - allocates memory for an array using malloc
 *@size: size
 *Return: void pointer
 */
void *custom_calloc(unsigned int size)
{
	char *a;
	unsigned int i;

	if (size == 0)
		return (NULL);
	a = malloc(size);
	if (a == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		a[i] = '\0';
	}
	return (a);
}
