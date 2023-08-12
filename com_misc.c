#include "main.h"
/**
 * exit_exec - handles error and freeing tokens and buffer on execve failure
 * @tokens: 2D pointer to the array of tokens
 * @n_tok: number of tokens
 * @buffer: pointer to the buffer to free
 * Return: No return
 */
void exit_exec(char **tokens, int n_tok, char *buffer)
{
	perror("!!!Error");
	free_grid(tokens, n_tok);
	free(buffer);
	exit(1);
}

/**
 * handle_signal - soft exiting at a given signal (ex. CTRL+C)
 * @sig: not used but useful
 * Return: No return
 */
void handle_signal(int sig)
{
	(void)sig;
	_putchar('\n');
	_puts(PROMPT);
}

/**
 * _getenv - gets a variable from environment given its name
 * @name: variable name
 * Return: the variable and its value as a string.
 */
char *_getenv(const char *name)
{
	int i = 0, len_name;
	char *var;

	if (name == NULL)
		return (NULL);
	len_name = _strlen((char *)name);
	var = malloc((len_name + 2) * sizeof(char));
	var = _strcpy(var, (char *)name);
	var = _strcat(var, "=");
	while (environ[i])
	{
		if (_strsearch(environ[i], var, 0) == 1)
		{
			free(var);
			return (_substr(environ[i], len_name));
		}
		i++;
	}
	free(var);
	return (NULL);
}

/**
 * _which - checks the path of a command
 * @env: the environment from which to fetch the path
 * @cmd: the command to check
 * Return: a pointer to the buffer holding the path, or NULL if no match
 */
char *_which(char *env[], char *cmd)
{
	int p, n_paths = 0, len_dir;
	char *env_path, *env_path_cpy, **paths, *path;
	struct stat st;

	env_path = _getenv("PATH");
	env_path_cpy = _strdup(env_path);
	paths = tokenizer(env_path_cpy, ":");
	free(env_path_cpy);
	n_paths = ctokens(paths);
	for (p = 0; p < n_paths; p++)
	{
		len_dir = _strlen(paths[p]);
		path = malloc((len_dir + _strlen(cmd) + 2) * sizeof(char));
		if (path == NULL)
		{
			perror("Error:");
			return (NULL);
		}
		_strcpy(path, paths[p]);
		_strcat(path, "/");
		_strcat(path, cmd);
		_strcat(path, "\0");
		if (stat(path, &st) == 0)
		{
			free_grid(paths, n_paths);
			return (path);
		}
		else
		{
			free(path);
		}
	}
	free_grid(paths, n_paths);
	return (NULL);
}
