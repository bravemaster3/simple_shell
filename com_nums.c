#include "main.h"

/**
 * _isdigit - checks for a digit
 * @c: character whose status to check
 * Return: 1 if digit, 0 otherwise
 */

int _isdigit(int c)
{
	int ret = 0;

	if (c >= 48 && c <= 57)
		ret = 1;
	return (ret);
}

/**
 * _isnumber - checks if a token only has digits
 * @str: string to check
 * Return: 1 if number, 0 otherwise
 */

int _isnumber(char *str)
{
	int i = 0;
	int ret = 1;

	if (str == NULL)
		return (0);
	while (str[i])
	{
		ret *= _isdigit(str[i]);
		i++;
	}
	return (ret);
}

/**
 * _pow - calculates x to the power y using recursion
 * @a: first integer
 * @b: second integer
 * Return: The result as an integer, -1  if y is negative
 */

int _pow(int a, int b)
{
	if (b < 0)
		return (-1);

	if (b == 0)
		return (1);

	if (b == 1)
		return (a);

	return (a * _pow(a, b - 1));
}

/**
 * _atoi - converts string to positive integer.
 * when str exceeds MAX_INT, the return is negative
 * @str: pointer to string
 * a check for whether the string is only digits
 * is performed before hand.
 * Return: retrieved integer
 */
int _atoi(char *str)
{
	int result = 0, i = 0, len = _strlen(str);

	while (str[i])
	{
		result += (str[i] - '0') * _pow(10, len - 1 - i);
		i++;
	}
	return (result);
}
