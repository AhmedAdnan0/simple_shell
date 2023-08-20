#include "func.h"

/**
 * check_delim - check if char is a delimieter
 * @c: character
 * @delim: delimeters
 *
 * Return: 1 TRUE
 *             0 FALSE
 */

int check_delim(char c, char *delim)
{
	int i = 0;

	while (delim[i])
	{
		if (c == delim[i])
			return (1);
		++i;
	}
	return (0);
}

/**
 * _strtok - tokenization  a string
 * @ptr: pointer to the string
 * @delim: delimeters
 *
 * Return: token
 */

char *_strtok(char *ptr, char *delim)
{
	static char *line;
	char *token;
	int i;

	if (ptr)
		line = _strdup(ptr);

	while (*line)
		if  (check_delim(*line, delim) == 1)
			*line++;

	for (i = 0; *line && !check_delim(*line, delim); ++i, *line++)
	{
	}

	token = malloc(i * sizeof(char));
	if (token == NULL)
		return (NULL);

	for (i  -= 1; i >= 0; --i)
		token[i] = line[i];

	return (token);
}

/*
 *	int main(void)
 *	{
 *		char *str = "Ahmed Adnan : Mohamed";
 *		char *token;
 *
 *		token = _strtok(str, " :");
 *
 *		while (token)
 *		{
 *			print_str(token);
 *			print_str("\n");
 *			token = _strtok(NULL, " :");
 *		}
 *		return (0);
 *	}
 */
