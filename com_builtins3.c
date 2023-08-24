#include "main.h"

/**
 * _getenvi - gets a variable from environment given its name
 * @name: variable name
 * Return: the index of the found var...
 */
int _getenvi(const char *name)
{
	int i = 0;
	char *var = NULL, *tmp = NULL;

	if (name == NULL)
		return (-1);
	tmp = _strdup((char *)name);
	var = _strcat(tmp, "=");
	free(tmp);
	while (environ[i])
	{
		if (_strsearch(environ[i], var, 0) == 1)
		{
			free(var);
			return (i);
		}
		i++;
	}
	free(var);
	return (0);
}

/**
 * builtin_setenv - sets the environmental variable given
 * @var: the variable
 * @value: the value of the variable
 * Return: nothing
 */

void builtin_setenv(char *var, char *value)
{
	int i = 0, num_entries = 0, indx = -1, add_size = 2;
	char *new_entry = NULL, **new_environ;

	if (_getenv(var) != NULL)
	{
		indx = _getenvi(var);
		add_size = 1;
	}
	new_entry = (char *)malloc(_strlen(var) + _strlen(value) + 2);
	if (new_entry == NULL)
		return;
	_strcpy(new_entry, var);
	_strcpy(new_entry + _strlen(var), "=");
	_strcpy(new_entry + _strlen(var) + 1, value);

	while (environ[num_entries] != NULL)
		num_entries++;
	new_environ = (char **)malloc((num_entries + add_size) * sizeof(char *));
	if (new_environ == NULL)
		return;
	for (i = 0; i < num_entries; i++)
	{
		if (i == indx)
		{
			new_environ[i] = _strdup(new_entry);
			free(new_entry);
		}
		else
			new_environ[i] = _strdup(environ[i]);
	}
	if (indx == -1)
	{
		new_environ[i] = _strdup(new_entry);
		free(new_entry);
	}
	new_environ[num_entries + 1] = NULL;

	environ = new_environ;
}

/**
 * builtin_cd - changes directory
 * @tokens: the array of tokens
 * @iter: the iteration for printing errors..
 * Return: no return
 */
void builtin_cd(char **tokens, UINT iter)
{
	int ret = 0;
	char *dir, *curr = NULL, cwd[4096];

	if (_getenv("OLDPWD") == NULL)
		builtin_setenv("OLDPWD", _getenv("PWD"));
	if (tokens[1] == NULL)
	{
		dir = _getenv("HOME");
		goto JUMPED;
	}
	if (_strcmp(tokens[1], "-") == 0)
	{
		ret = chdir(_getenv("OLDPWD"));
		if (ret == 0)
		{
			_puts(_getenv("OLDPWD"));
			_putchar('\n');
		}
		return;
	}
	else if (_strcmp(tokens[1], "$HOME") == 0)
		dir = _getenv("HOME");
	else
		dir = tokens[1];
JUMPED:
	if (getcwd(cwd, sizeof(cwd)) != NULL)
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
