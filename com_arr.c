#include "main.h"

/**
 * _getline - reads line from a stream until \n is found
 * @lineptr: double pointer to the buffer where chars read are storred
 * @n: the pointer to the variable for the count of nchars read
 * @stream: which file stream the reading is done from
 * Return: nchars read, or -1 if a problem occured
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t total = 0;
	int fd;
	unsigned char c;
	char *new_ptr;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);
	if (*lineptr == NULL || *n == 0)
	{
		*n = 64;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}
	fd = stream->_fileno;
	while ((read(fd, &c, 1)) == 1)
	{
		if (total >= *n - 1)
		{
			*n *= 2;
			new_ptr = (char *)_realloc(*lineptr, (*n) / 2, *n);
			if (new_ptr == NULL)
				return (-1);/*return((free(*lineptr)), -1);*/
			*lineptr = new_ptr;
		}
		(*lineptr)[total] = c;
		total++;
		if (c == '\n')
			return (((*lineptr)[total] = '\0'), total);
	}
	if (total > 0)
		return (((*lineptr)[total] = '\0'), total);
	return (-1);
}

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
	token = _strtok(buff_cpy, delim);
	if (token == NULL)
	{
		free(buff_cpy);
		return (NULL);
	}
	n_tok = 1;
	while ((token = _strtok(NULL, delim)))
		n_tok++;
	free(buff_cpy);

	tokens = (char **)malloc(sizeof(char *) * (n_tok + 1));
	if (tokens == NULL)
	{
		perror("Memory allocation failed\n");
		exit(1);
	}
	token = _strtok(buffer, delim);
	counter = 0;
	while (token)
	{
		tokens[counter] = _strdup(token);
		token = _strtok(NULL, delim);
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
