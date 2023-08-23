#include "main.h"


/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1 as length of printed char.
 * On error, 0 is returned, because no chars printed
 */
int _putchar(char c)
{
	int ret = write(1, &c, 1);

	if (ret == 1)
		return (1);

	return (0);
}



/**
 * _puts - prints a string, prints (null) for NULL str
 * @str: the string to print
 *
 * Return: the number of bytes printed
 */
int _puts(char *str)
{
	int n_by = 0;

	if (str == NULL)
		str = "(null)";

	while (str[n_by] != '\0')
	{
		_putchar(str[n_by]);
		n_by++;
	}

	return (n_by);
}
