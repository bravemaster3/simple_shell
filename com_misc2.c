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
