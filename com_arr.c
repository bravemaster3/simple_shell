#include "main.h"

/**
 * tokenizer - tokenizes a buffer
 * @buffer: the buffer
 * @delim: delimiter
 *
 * Return: a 2D pointer to the tokens...
 */
char **tokenizer(char *buffer, char *delim)
{
	char *buff_cpy, *token, **tokens;
	int n_tok, counter;

	buff_cpy = _strdup(buffer);
	token = strtok(buff_cpy, delim);
	n_tok = 1;
	while ((token = strtok(NULL, delim)))
		n_tok++;
	free(buff_cpy);

	tokens = (char **)malloc(sizeof(char *) * (n_tok + 1));
	if (tokens == NULL)
	{
		perror("Memory allocation failed\n");
		exit(1);
	}
	token = strtok(buffer, delim);
	counter = 0;
	while (token)
	{
		tokens[counter] = _strdup(token);
		token = strtok(NULL, delim);
		counter++;
	}
	tokens[n_tok] = NULL;
	return (tokens);
}

/**
 * ctokens - counts the number of tokens in a 2D array
 * @tokens: pointer to the first element of the 2D array
 * Return: number of tokens
 */

int ctokens(char **tokens)
{
	int count = 0;

	if (tokens == NULL)
		return (0);
	while (tokens[count])
		count++;
	return (count);
}

/**
 * free_grid - frees all allocated memory of a grid
 * @grid:: pointer (double pointer) to the grid
 * @height: the number of rows of the grid
 * Return: no return
 */

void free_grid(char **grid, int height)
{
	int row = 0;

	for (; row < height; row++)
		free(grid[row]);
	free(grid);
}
