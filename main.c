#include "main.h"

/**
 * checks - does some simple checks before exiting on CTRL+D
 * @buff: the buffer
 * @n: the number of chars
 * Return: nothing
 */
void checks(char *buff, int n)
{
	if (n == -1)
	{
		free(buff);
		exit(errno);
	}
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
		if (mode == 1)
			_puts(PROMPT);
		n_chars = getline(&buffer, &size, stdin);
		if (n_chars == 1 && buffer[0] == '\n')
			continue;
		checks(buffer, n_chars);
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
		} else
			wait(&status);
		free(path);
		free_grid(tokens, n_tok);
	}
	free(buffer);
	return (0);
}
