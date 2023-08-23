#include "main.h"

/**
 * exit_exec - handles error and freeing tokens and buffer on execve failure
 * @tokens: 2D pointer to the array of tokens
 * @n_tok: number of tokens
 * @buffer: pointer to the buffer to free
 * @path: the path
 * @iter: current iteration
 * Return: No return
 */
void exit_exec(char **tokens, int n_tok, char *buffer, char *path, UINT iter)
{
	free(path);
	print_err(iter, "", "");
	perror("");
	free_grid(tokens, n_tok);
	free(buffer);
	exit(errno);
}

/**
 * not_found - handles error and freeing tokens and buffer on execve failure
 * @tokens: 2D pointer to the array of tokens
 * @n_tok: number of tokens
 * @iter: current iteration
 * Return: No return
 */
void not_found(char **tokens, int n_tok, UINT iter)
{
	/*perror(_getenv("_"));*/
	errno = 127;
	print_err(iter, tokens[0], "not found\n");
	free_grid(tokens, n_tok);
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
	char *var = NULL, *tmp = NULL;

	if (name == NULL)
		return (NULL);
	len_name = _strlen((char *)name);
	tmp = _strdup((char *)name);
	var = _strcat(tmp, "=");
	free(tmp);
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
 * @cmd: the command to check
 * Return: a pointer to the buffer holding the path, or NULL if no match
 */
char *_which(char *cmd)
{
	int p, n_paths = 0, errno_cpy = errno;
	char *env_path = NULL, *env_path_cpy = NULL;
	char **paths = NULL, *path = NULL, *tmp = NULL, *tmp2 = NULL;

	env_path = _getenv("PATH");
	env_path_cpy = _strdup(env_path);
	paths = tokenizer(env_path_cpy, ":");
	free(env_path_cpy);
	n_paths = ctokens(paths);
	for (p = 0; p < n_paths; p++)
	{
		tmp = _strdup(paths[p]);
		tmp2 = _strcat(tmp, "/");
		free(tmp);
		path = _strcat(tmp2, cmd);
		free(tmp2);
		if (access(path, X_OK) == 0)
		{
			free_grid(paths, n_paths);
			errno = errno_cpy;
			return (path);
		}
		else
			free(path);
	}
	if (access(cmd, X_OK) == 0)
	{
		path = _strdup(cmd);
		errno = errno_cpy;
		if (is_path(path))
		{
			free_grid(paths, n_paths);
			return (path);
		}
		free(path);
	}
	free_grid(paths, n_paths);
	errno = errno_cpy;
	return (NULL);
}
