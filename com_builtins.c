#include "main.h"

/**
 * builtins - handling built commands
 * @tokens: array of tokens
 * @n_tok: number of tokens
 * @buffer: the buffer
 * @iter: current iteration
 * Return: nothing
 */
void builtins(char **tokens, int n_tok, char *buffer, UINT iter)
{
	char *cmd = tokens[0];

	if (strcmp(cmd, "exit") == 0)
	{
		builtin_exit(tokens, n_tok, buffer, iter);
	}
	else if (strcmp(cmd, "env") == 0)
	{
		builtin_env();
	}
	else if (strcmp(cmd, "cd") == 0)
	{
	}
	else
	{
		not_found(tokens, n_tok, iter);
	}
}

/**
 * builtin_exit - handles builtin command exit
 * @tokens: array of tokens
 * @n_tok: number of tokens
 * @buffer: the buffer
 * @iter: current iteration
 * Return: nothing
 */

void builtin_exit(char **tokens, int n_tok, char *buffer, UINT iter)
{
	int status, isvalid_status = 1;

	if (tokens[1] == NULL)
		status = errno;
	else if (_isnumber(tokens[1]) && _atoi(tokens[1]) >= 0)
	{
		if (_atoi(tokens[1]) <= 255)
			status = _atoi(tokens[1]);
		else
			status = _atoi(tokens[1]) % 256;
	}
	else
		isvalid_status = 0;

	if (isvalid_status == 1)
	{
		free(buffer);
		free_grid(tokens, n_tok);
		exit(status);
	}
	print_err(iter, tokens[0], "Illegal number: ");
	_puts2(tokens[1], 2);
	_putchar2('\n', 2);
	errno = 2;
	free_grid(tokens, n_tok);
}

/**
 * builtin_env - prints the environment of the system
 * Return: nothing
 */
void builtin_env(void)
{
	int i = 0;

	while (environ[i])
	{
		_puts(environ[i]);
		i++;
	}
}
