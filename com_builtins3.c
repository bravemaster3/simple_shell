#include "main.h"

/**
 * builtin_cd - changes directory
 * @tokens: the array of tokens
 * @iter: the iteration for printing errors..
 * Return: no return
 */
void builtin_cd(char **tokens, UINT iter)
{
	int ret = 0;
	char *dir, *prev = NULL, *curr = NULL, cwd[PATH_MAX];

	if (_getenv("OLDPWD") == NULL)
		builtin_setenv("OLDPWD", _getenv("PWD"));
	if (tokens[1] == NULL)
	{
		dir = _getenv("HOME");
		goto JUMPED;
	}
	if (_strcmp(tokens[1], "-") == 0)
	{
		prev = _getenv("OLDPWD");
		ret = chdir(prev);
		if (ret == 0)
		{
			_puts(prev);
			_putchar('\n');
		}
		return;
	}
	else if (_strcmp(tokens[1], "$HOME") == 0)
		dir = _getenv("HOME");
	else
		dir = tokens[1];
JUMPED:
	builtin_setenv("OLDPWD", getcwd(cwd, sizeof(cwd)));
	ret = chdir(dir);
	if (ret == -1 && tokens[1] != NULL)
	{
		print_err(iter, tokens[0], "can't cd to ");
		_puts2(tokens[1], STDERR_FILENO);
		_putchar2('\n', STDERR_FILENO);
	}
	if (ret == 0)
	{
		curr = getcwd(cwd, sizeof(cwd));
		if (curr != NULL)
			builtin_setenv("PWD", cwd);
	}
}
