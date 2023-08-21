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
	char *tmp_str;
	int i = 0;

	tmp_str = _strcat(var, "=");
	while (environ[i] != NULL)
	{
		if (_strsearch(environ[i], tmp_str, 0) == 1)
		{
			free(tmp_str);
			return (i);
		}
		i++;
	}
	return (-1);
}

/**
 * env_cpy - copy environmental variables
 * @dest: destination array
 * @sind: start index
 * @eind: stop index
 * Return: destination array address
 */
char **env_cpy(char **dest, int sind, int eind)
{
	int i;

	for (i = sind; i < eind; i++)
		dest[i] = _strdup(environ[i]);

	return (dest);
}

/**
 * builtin_setenv - sets the environmental variable given
 * @var: the variable
 * @value: the value of the variable
 * Return: nothing
 */
void builtin_setenv(char *var, char *value)
{
	char **env_dup;
	char *tmp;
	int env_size = cenvs();
	int var_index;

	tmp = _strcat(var, "=");
	env_dup = (char **)malloc((env_size + 1) * sizeof(char *));
	if (_getenv(var) == NULL)
	{
		/* Do create new variable and set it's value */
		env_dup = env_cpy(env_dup, 0, env_size);
		var_index = env_size;
		env_dup[var_index] = _strcat(tmp, value);
		env_dup[env_size + 1] = NULL;
	} else
	{
		/* Do re-allocation of the variable */
		var_index = eindex(var);
		env_dup = env_cpy(env_dup, 0, var_index);
		env_dup[var_index] = _strcat(tmp, value);
		env_dup = env_cpy(env_dup, var_index + 1, env_size);
		env_dup[env_size + 1] = NULL;
	}
	free(tmp);
	printf("Last: %s\n", env_dup[var_index]);
	environ = env_dup;
}


/**
 * builtin_unsetenv - unsets the environmental variable
 * @var: the variable given
 * Return: nothing
 */
void builtin_unsetenv(char *var)
{
	if (_getenv(var))
	{
		/* do some unsetting */
	}
	/* do noting if the variable does not exist */
}
