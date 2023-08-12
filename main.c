#include <sys/wait.h>
#include <signal.h>
#include "main.h"

/**
 * checks - does some simple checks
 * @buff: the buffer
 * @n: the number of chars
 * Return: nothing
 */
void checks(char *buff, int n)
{
	if (n == -1)
	{
		free(buff);
		exit(0);
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
	int n_tok, status;
	char *buffer = NULL, *delim = " \n", **tokens, *path;
	pid_t child_pid;

	signal(SIGINT, handle_signal);
	while (1)
	{
		_puts(PROMPT);
		n_chars = getline(&buffer, &size, stdin);
		if (n_chars == 1 && buffer[0] == '\n')
			continue;
		checks(buffer, n_chars);
		tokens = tokenizer(buffer, delim);
		n_tok = ctokens(tokens);
		path = _which(tokens[0]);
		if (path == NULL)
		{
			not_found(tokens, n_tok, buffer);
			continue;
		}
		child_pid = fork();
		if (child_pid == -1)
			exit_exec(tokens, n_tok, buffer, path);
		else if (child_pid == 0)
		{
			if (execve(path, tokens, env) == -1)
				exit_exec(tokens, n_tok, buffer, path);
		} else
			wait(&status);
		free(path);
		free_grid(tokens, n_tok);
	}
	free(buffer);
	return (0);
}

