#include "main.h"

/**
 * _memcpy - copies n bytes from src to dest
 * @dest: destination memory area
 * @src: source memory area
 * @n: number of bytes to copy
 * Return: a pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	return (dest);
}

/**
 * _realloc - memory reallocation using malloc
 * @ptr: pointer to the previous block
 * @old_size: old size in bytes
 * @new_size: new size in bytes
 * Return: pointer to the new memory (or old one if no change)
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *nptr;
	unsigned int n;

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	nptr = malloc(new_size);
	if (nptr == NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr != NULL)
	{
		n = (new_size < old_size) ? new_size : old_size;
		_memcpy(nptr, ptr, n);
	}

	free(ptr);

	return (nptr);
}
