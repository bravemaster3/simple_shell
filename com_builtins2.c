#include "main.h"

/**
 * builtin_setenv - sets the environmental variable given
 * @var: the variable
 * @value: the value of the variable
 * Return: nothing
 */
void builtin_setenv(char *var, char *value)
{
	(void)value;
	if (_getenv(var) == NULL)
	{
		/* Do create new variable and set it's value */
	} else
	{
		/* Do re-allocation of the variable */
	}
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
