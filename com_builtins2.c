#include "main.h"

/**
 * cenvs - count environmental variables
 * Return: number of variables
 */
unsigned int cenvs(void)
{
	int i = 0;

	while (environ[i] != NULL)
		i++;
	return (i);
}

/**
 * eindex - find the index of an existing variable
 * @var: the variable we are looking for
 * Return: index of the varibale, else -1
 */
int eindex(char *var)
{
	char *tmp_str, *tmp;
	int i = 0;

	tmp_str = _strcat(var, "=");
	tmp = _strdup(tmp_str);
	free(tmp_str);
	while (environ[i] != NULL)
	{
		if (_strsearch(environ[i], tmp, 0) == 1)
		{
			free(tmp);
			return (i);
		}
		i++;
	}
	free(tmp);
	return (-1);
}

/**
 * env_cpy - copy environmental variables
 * @dest: destination array
 * @sind: start index
 * @eind: stop index
 * @include: including on the environ index
 * Return: destination array address
 */
char **env_cpy(char **dest, int sind, int eind, int include)
{
	int i;

	for (i = sind; i < eind; i++)
		dest[i] = environ[i + include];

	return (dest);
}

/**
 * builtin_setenv_old - sets the environmental variable given
 * @var: the variable
 * @value: the value of the variable
 * Return: nothing
 */
void builtin_setenv_old(char *var, char *value)
{
	char **env_dup = NULL;
	char *tmp = NULL, *tmp_full = NULL;
	int env_size = cenvs(), new_size = 0;
	int var_index = 0;

	tmp = _strcat(var, "=");
	tmp_full = _strcat(tmp, value);
	free(tmp);
	if (eindex(var) != -1)
	{
		new_size = env_size + 2;
		env_dup = (char **)malloc(new_size * sizeof(char *));
		env_dup = env_cpy(env_dup, 0, new_size - 2, 0);
		var_index = env_size;
		env_dup[var_index] = _strdup(tmp_full);
		env_dup[new_size - 1] = NULL;
	}
	else
	{
		env_dup = (char **)malloc((env_size + 1) * sizeof(char *));
		var_index = eindex(var);
		env_dup = env_cpy(env_dup, 0, var_index, 0);
		env_dup[var_index] = _strdup(tmp_full);
		env_dup = env_cpy(env_dup, var_index + 1, env_size - 2, 0);
		env_dup[env_size - 1] = NULL;
	}
	free(tmp_full);
	environ = env_dup;
}

/**
 * builtin_unsetenv - unsets the environmental variable
 * @var: the variable given
 * Return: nothing
 */
void builtin_unsetenv(char *var)
{
	char **env_dup;
	int index = eindex(var);
	int env_size = cenvs();

	if (eindex(var) != -1)
	{
		env_dup = malloc((env_size - 1) * sizeof(char *));
		env_dup = env_cpy(env_dup, 0, index, 0);
		env_dup = env_cpy(env_dup, index, env_size - 3, 1);
		env_dup[env_size - 2] = NULL;

		environ = env_dup;
	}
	/* do noting if the variable does not exist */
}
