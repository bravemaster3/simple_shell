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
		_putchar('\n');
		if (errno == 127)
			exit(2);
		else
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
	size_t size = 0;
	ssize_t n_chars;
	int n_tok, status, mode = isatty(0);
	UINT iter = 0;
	char *buffer = NULL, *delim = " \"\n", **tokens, *path;
	pid_t child_pid;

	signal(SIGINT, handle_signal);
	errno = 0;
	while (1)
	{
		iter++;
		if (mode == 1)
			_puts(PROMPT);
		n_chars = getline(&buffer, &size, stdin);
		if (n_chars == 1 && buffer[0] == '\n')
			continue;
		checks(buffer, n_chars); /*CTRL+D implementation is here*/
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
		{
			wait(&status);
			errno = status;
		}

		free(path);
		free_grid(tokens, n_tok);
	}
	free(buffer);
	return (0);
}
