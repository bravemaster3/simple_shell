#include "main.h"

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
		memcpy(nptr, ptr, n);
	}
	free(ptr);
	return (nptr);
}
