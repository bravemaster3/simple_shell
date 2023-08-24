#include "main.h"

/**
 * _putchar2 - writes the character c to stdout
 * @c: The character to print
 * @fd: file descriptor, 0 for stdin, 1 for stdout and 2 for stderr
 * Return: On success 1 as length of printed char.
 * On error, 0 is returned, because no chars printed
 */
int _putchar2(char c, int fd)
{
	int ret = write(fd, &c, 1);

	if (ret == 1)
		return (1);
	return (0);
}

/**
 * _puts2 - prints a string to stderr, prints (null) for NULL str
 * @str: the string to print
 * @fd: file descriptor, 0 for stdin, 1 for stdout and 2 for stderr
 *
 * Return: the number of bytes printed
 */
int _puts2(char *str, int fd)
{
	int n_by = 0;

	if (str == NULL)
		str = "(null)";

	while (str[n_by] != '\0')
	{
		_putchar2(str[n_by], fd);
		n_by++;
	}

	return (n_by);
}

/**
 * print_uint - prints unsigned integer
 * @n: unsigned integer to be printed
 * @fd: file descriptor, 0 for stdin, 1 for stdout and 2 for stderr
 * Return: the number of bytes printed
 */

int print_uint(unsigned int n, int fd)
{
	int n_by = 0, i, j = 0, base = 10;
	unsigned int n_cpy = n;
	char *arr;

	if (n == 0)
	{
		_putchar2('0', fd);
		return (1);
	}
	while (n_cpy > 0)
	{
		n_by++;
		n_cpy /= base;
	}
	arr = (char *)malloc((n_by + 1) * sizeof(char));
	if (arr == NULL)
		free(arr);
	else
	{
		for (i = n_by - 1; i >= 0; i--)
		{
			arr[i] = (n % base) + '0';
			n /= base;
		}
		arr[n_by] = '\0';

		while (arr[j] != '\0')
		{
			_putchar2(arr[j], fd);
			j++;
		}
		free(arr);
	}
	return (j);
}

/**
 * print_err - custom perror to the stderr
 * @iter: currrent iteration
 * @cmd: command executed
 * @message: message to append
 * Return: No return
 */

void print_err(UINT iter, char *cmd, char *message)
{
	_puts2("./hsh", 2);
	_puts2(": ", 2);
	print_uint(iter, 2);
	_puts2(": ", 2);
	_puts2(cmd, 2);
	_puts2(": ", 2);
	_puts2(message, 2);
}
