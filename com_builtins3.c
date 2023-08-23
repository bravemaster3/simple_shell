#include "main.h"

/**
 * builtin_cd - changes directory
 * @tokens: the array of tokens
 * @iter: the iteration for printing errors..
 * @env: environment passed from the main
 * Return: changed env
 */
char **builtin_cd(char **tokens, UINT iter, char **env)
{
	int ret = 0;
	char *dir, *prev = NULL, *curr = NULL, cwd[4096];

	curr = getcwd(cwd, sizeof(cwd));
	if (_getenv("PREV_PWD", env) == NULL)
		builtin_setenv2("PREV_PWD", cwd, env);
	if (tokens[1] == NULL)
	{
		dir = _getenv("HOME", env);
		goto JUMPED;
	}
	if (_strcmp(tokens[1], "-") == 0)
	{
		prev = _getenv("PREV_PWD", env);
		ret = chdir(prev);
		if (ret == 0)
		{
			_puts(prev);
			_putchar('\n');
		}
		return (env);
	} else if (_strcmp(tokens[1], "$HOME") == 0)
		dir = _getenv("HOME", env);
	else
		dir = tokens[1];
JUMPED:
	builtin_setenv2("PREV_PWD", getcwd(cwd, sizeof(cwd)), env);
	ret = chdir(dir);
	if (ret == -1 && tokens[1] != NULL)
	{
		print_err(iter, tokens[0], "can't cd to ", env);
		_puts2(tokens[1], STDERR_FILENO);
		_putchar2('\n', STDERR_FILENO);
	} else
	{
		curr = getcwd(cwd, sizeof(cwd));
		if (curr != NULL)
			builtin_setenv2("PWD", cwd, env);
	}
	return (env);
}
