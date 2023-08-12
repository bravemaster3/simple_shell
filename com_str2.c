#include "main.h"

/**
 * _strsearch - search for a given string
 * @hay: the string to search
 * @needle: the needdle
 * @index: starting point
 *
 * Return: 1 - found, else 0
 */
int _strsearch(char *hay, char *needle, int index)
{
	if (_strlen(hay) <= index || (_strlen(needle) + index) > _strlen(hay))
		return (0);
	while (*needle != '\0')
	{
		if (hay[index] != *needle)
			return (0);
		index++;
		needle++;
	}
	return (1);
}

/**
 * _substr - get the substring from a given index
 * @str: the string to get from
 * @index: the starting point
 *
 * Return: return substring if there, else NULL
 */
char *_substr(char *str, int index)
{
	char i;

	if (_strlen(str) <= index)
		return (NULL);
	for (i = 0; i <= index; i++)
		str++;
	return (str);
}
