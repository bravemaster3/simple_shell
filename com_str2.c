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

/**
 * _strcmp - compares 2 strings,
 * @s1: pointer to string 1
 * @s2: pointer to string 2
 * Return: 0 if strings are the same,
 * the difference between the first different digits otherwise
 */

int _strcmp(char *s1, char *s2)
{
	int stp = 0;
	char *s1_c = s1;
	char *s2_c = s2;
	int ret = 0;

	while (*s1_c != '\0' && *s2_c != '\0' && stp == 0)
	{
		ret = (*s1_c) - (*s2_c);
		if (*s1_c != *s2_c)
			stp = 1;
		s1_c++;
		s2_c++;
	}
	return (ret);
}
