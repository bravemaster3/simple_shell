#include "main.h"

/**
 * cenvs2 - count environmental variables
 * @env: env gotten from the main
 * Return: number of variables
 */
unsigned int cenvs2(char **env)
{
	int i = 0;

	while (env[i] != NULL)
		i++;
	return (i);
}

/**
 * eindex2 - find the index of an existing variable
 * @var: the variable we are looking for
 * @env: env gotten from the main
 * Return: index of the varibale, else -1
 */
int eindex2(char *var, char **env)
{
	char *tmp_str;
	int i = 0;

	tmp_str = _strcat(var, "=");
	while (env[i] != NULL)
	{
		if (_strsearch(env[i], tmp_str, 0) == 1)
		{
			free(tmp_str);
			return (i);
		}
		i++;
	}
	return (-1);
}

/**
 * env_cpy2 - copy environmental variables
 * @dest: destination array
 * @sind: start index
 * @eind: stop index
 * @env: env gotten from the main
 * Return: destination array address
 */
char **env_cpy2(char **dest, int sind, int eind, char **env)
{
	int i;

	for (i = sind; i < eind; i++)
		dest[i] = _strdup(env[i]);

	return (dest);
}

/**
 * builtin_setenv2 - sets the environmental variable given
 * @var: the variable
 * @value: the value of the variable
 * @env: env gotten from the main
 * Return: the changed env
 */
char **builtin_setenv2(char *var, char *value, char **env)
{
	char **env_dup;
	char *tmp;
	int env_size = cenvs2(env);
	int var_index;

	tmp = _strcat(var, "=");
	env_dup = (char **)malloc((env_size + 1) * sizeof(char *));
	if (_getenv(var, env) == NULL)
	{
		/* Do create new variable and set it's value */
		env_dup = env_cpy2(env_dup, 0, env_size, env);
		var_index = env_size;
		env_dup[var_index] = _strcat(tmp, value);
		env_dup[env_size + 1] = NULL;
	}
	else
	{
		/* Do re-allocation of the variable */
		var_index = eindex2(var, env);
		env_dup = env_cpy2(env_dup, 0, var_index, env);
		env_dup[var_index] = _strcat(tmp, value);
		env_dup = env_cpy2(env_dup, var_index + 1, env_size, env);
		env_dup[env_size + 1] = NULL;
	}
	free(tmp);
	env = env_dup;
	return (env);
}

/**
 * builtin_unsetenv2 - unsets the environmental variable
 * @var: the variable given
 * @env: env gotten from the main
 * Return: nothing
 */
void builtin_unsetenv2(char *var, char **env)
{
	(void)env;
	if (_getenv(var, env))
	{
		/* do some unsetting */
	}
	/* do noting if the variable does not exist */
}
