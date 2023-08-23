#include "main.h"

/**
 * isbuiltin - checks if a cmd is a builtin
 * @cmd: command to check
 * Return: 1 if a builtin, 0 otherwise
 */
int isbuiltin(char *cmd)
{
	int i = 0;
	char *builtins[] = {"exit", "env", "cd", "setenv", "unsetenv", NULL};

	while (builtins[i] != NULL)
	{
		if (_strcmp(builtins[i], cmd) == 0)
			return (1);
		i++;
	}
	return (0);
}
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

	if (_strcmp(cmd, "exit") == 0)
		builtin_exit(tokens, n_tok, buffer, iter);
	else if (_strcmp(cmd, "env") == 0)
		builtin_env();
	else if (_strcmp(cmd, "setenv") == 0)
	{
		if (n_tok < 3 || n_tok > 3)
		{
			_puts2("setenv: Usage: setenv VARIABLE VALUE\n", STDERR_FILENO);
			return;
		}
		builtin_setenv(tokens[1], tokens[2]);
	}
	else if (_strcmp(cmd, "unsetenv") == 0)
	{
		if (n_tok < 2 || n_tok > 2)
		{
			_puts2("unsetenv: Usage: unsetenv VARIABLE\n", STDERR_FILENO);
			return;
		}
		builtin_unsetenv(tokens[1]);
	}
	else if (_strcmp(cmd, "cd") == 0)
		builtin_cd(tokens, iter);
	else
		not_found(tokens, n_tok, iter);
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
	_puts2(tokens[1], STDERR_FILENO);
	_putchar2('\n', STDERR_FILENO);
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
		_putchar('\n');
		i++;
	}
}
