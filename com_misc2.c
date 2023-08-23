#include "main.h"


/**
 * is_path - checks if a string is a path
 * we do so just by testing if a given string starts with / or ./
 * Note that this is used only after checking that the file exists
 * @str: the string to check
 * Return: 1 if it is a path, 0 otherwise
 */
int is_path(char *str)
{
	/*char *path = _strcat("./", str);*/
	int errno_cpy = errno;

	if (access(str, F_OK) == 0 && (str[0] == '/' || str[0] == '.'))
		return (1);

	errno = errno_cpy;
	/*free(path);*/
	return (0);
}


/**
 * isdelim - checks whether the given character is part of the delimiter
 * @c: the character
 * @delim: the delimeter string
 * Return: 1 - if true, and 0 if not
 */
int isdelim(char c, char *delim)
{
	while (*delim != '\0')
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}

/**
 * _strtok - extract tokens from a given string
 * @src: the source string
 * @delim: the delimiter
 * Return: a pointer to the next toke, or NULL if there are no more tokens
 */
char *_strtok(char *src, char *delim)
{
	static char *bkp;
	char *ret;

	if (src == NULL)
		src = bkp;
	if (src == NULL)
		return (NULL);

	while (1)
	{
		if (isdelim(*src, delim))
		{
			src++;
			continue;
		}
		if (*src == '\0')
			return (NULL);
		break;
	}
	ret = src;
	while (1)
	{
		if (*src == '\0')
		{
			bkp = src;
			return (ret);
		}

		if (isdelim(*src, delim))
		{
			*src = '\0';
			bkp = src + 1;
			return (ret);
		}
		src++;
	}
}
