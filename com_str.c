#include "main.h"

/**
 * _strcpy - copies string pointed to by src to another variable
 * @dest: pointer var to a buffer where to copy the string
 * @src: pointer var to the source of the string to be copied
 * Return: the pointer to dest i.e. the address
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: pointer to the first char of destination string
 * @src: pointer to the first char of source string
 * Return: pointer to the concatenated string
 */

char *_strcat(char *dest, char *src)
{
	int i, j;
	const int size_dest = _strlen(dest);
	const int size_src = _strlen(src);

	for (i = 0; i <= size_src - 1; i++)
	{
		j = size_dest + i;
		dest[j] = src[i];
	}

	return (dest);
}

/**
 * _strlen - returns the length of a function using recursion
 * @s: pointer to the string
 * Return: the length of the string as integer
 */

int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;
	return (len);
}

/**
 * _strdup - duplicates a string
 * @str: pointer to the string to duplicate
 * Return: pointer to the copy of the string
 */

char *_strdup(char *str)
{
	char *str_cpy;
	int len, i;

	if (str == NULL)
		return (NULL);

	len = _strlen(str) + 1;

	str_cpy = malloc(sizeof(*str_cpy) * len);

	if (str_cpy == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		str_cpy[i] = str[i];

	return (str_cpy);
}

/**
 * free_grid - frees all allocated memory of a grid
 * @grid:: pointer (double pointer) to the grid
 * @height: the number of rows of the grid
 * Return: no return
 */

void free_grid(char **grid, int height)
{
	int row = 0;

	for (; row < height; row++)
		free(grid[row]);
	free(grid);
}
