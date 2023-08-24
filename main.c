#include "main.h"

/**
 * checks - does some simple checks before exiting on CTRL+D
 * @buff: the buffer
 * @n: the number of chars
 * @mode: 1 for interactive, 0 otherwise
 * Return: nothing
 */
void checks(char *buff, int n, int mode)
{
	int i;

	if (n == -1)
	{
		free(buff);
		if (mode == 1)
			_putchar('\n');
		exit(errno);
	}
	else
	{
		for (i = 0; i < _strlen(buff); i++)
		{
			if (_strncmp(buff + i, "#", 1) == 0)
				buff[i] = '\0';
			else
				continue;
		}
	}
}

/**
 * wait_on_child - wrapper for process waiting on child, and fetching errno
 * @status: status integer that will be set after process exists
 * Return: no return
 */
void wait_on_child(int *status)
{
	wait(status);
	errno = _WEXITSTATUS(*status);
}
/**
 * free_path_tokens - wrapper for freeing both path and tokens
 * @path: a string representing a path
 * @tokens: a 2D array of tokens
 * @n_tok: the number of tokens in tokens
 * Return: no return
 */
void free_path_tokens(char *path, char **tokens, int n_tok)
{
	free(path);
	free_grid(tokens, n_tok);
}

/**
 * main - entry point, read line and print all arguments
 * @ac: argument count
 * @av: arguments
 * @env: environment
 * Return: 0 on success
 */
int main(UNUSED int ac, UNUSED char **av, char **env)
{
	size_t size = 0, iter = 0, n_chars = 0;
	int n_tok, status, mode = isatty(0);
	char *buffer = NULL, *delim = " \"\n", **tokens, *path;
	pid_t child_pid;

	errno = 0;
	signal(SIGINT, handle_signal);
	while (1)
	{
		iter++;
		(mode == 1) ? _puts(PROMPT) : 0;
		n_chars = _getline(&buffer, &size, stdin);
		if (n_chars == 1 && buffer[0] == '\n')
			continue;
		checks(buffer, n_chars, mode);
		tokens = tokenizer(buffer, delim);
		n_tok = ctokens(tokens);
		if (tokens == NULL)
			continue;
		path = _which(tokens[0]);
		if (path == NULL)
		{
			builtins(tokens, n_tok, buffer, iter);
			continue;
		}
		child_pid = fork();
		if (child_pid < 0)
			exit_exec(tokens, n_tok, buffer, path, iter);
		else if (child_pid == 0)
		{
			if (execve(path, tokens, env) == -1)
				exit_exec(tokens, n_tok, buffer, path, iter);
		}
		else
			wait_on_child(&status);
		free_path_tokens(path, tokens, n_tok);
	}
	free(buffer);
	return (0);
}
