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

/**
 * _strcat - concatenates two strings
 * @dest: pointer to the first char of destination string
 * @src: pointer to the first char of source string
 * Return: pointer to the concatenated string
 */
char *_strcat(char *dest, char *src)
{
	int i, j;
	char *result = NULL;
	int size_dest = _strlen(dest);
	int size_src = _strlen(src);

	result = malloc((size_dest + size_src + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	for (i = 0; i <= size_dest - 1; i++)
		result[i] = dest[i];
	for (i = 0; i <= size_src - 1; i++)
	{
		j = size_dest + i;
		result[j] = src[i];
	}
	result[j + 1] = '\0';

	return (result);
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

