#include <sys/wait.h>
#include <signal.h>
#include "main.h"

/**
 * main - entry point, read line and print all arguments
 * @argc: argument count
 * @argv: arguments
 * @envp: environment
 * Return: 0 on success
 */
int main(int argc, char **argv, char *envp[])
{
	size_t size = 0;
	ssize_t n_chars;
	int n_tok, status;
	char *buffer = NULL, *delim = " \n", **tokens;
	pid_t child_pid;

	(void)argv;
	(void)argc;
	signal(SIGINT, handle_signal);
	while (1)
	{
		_puts(PROMPT);
		n_chars = getline(&buffer, &size, stdin);
		if (n_chars == 1 && buffer[0] == '\n')
			continue;
		if (n_chars == -1)
		{
			free(buffer);
			printf("I received termination signal!!!\n");
			exit(0);
		}
		tokens = tokenizer(buffer, delim);
		n_tok = ctokens(tokens);
		child_pid = fork();
		if (child_pid == -1)
			exit_exec(tokens, n_tok, buffer);
		else if (child_pid == 0)
		{
			if (execve(tokens[0], tokens, envp) == -1)
				exit_exec(tokens, n_tok, buffer);
		}
		else
			wait(&status);
		free_grid(tokens, n_tok);
	}
	free(buffer);
	return (0);
}

