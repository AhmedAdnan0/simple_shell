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
 * comment_handler - handling comments
 * @str: command
 */

void comment_handler(char **str)
{
	int i;
	char *s = *str;

	for (i = 0; s[i]; ++i)
		if (s[i] == '#' && (i == 0 || s[i - 1] == ' ' ||
			s[i - 1] == '\n' || s[i - 1] == '\t'))
			break;

	if (s[i] == '#')
		for (; s[i]; ++i)
			s[i] = '\0';
}

/**
 * echo - builtin echo cmd
 * @arg: echo args
 */

void echo(char **arg/*, const char **env*/)
{
	int /*i, */j;
	/*char *var, *val;*/

	for (j = 1; arg[j]; ++j)
	{
		if (_strcmp(arg[j], "$$") == 0)
			print_int(getpid());

		else if (_strcmp(arg[j], "$\?") == 0)
			print_int(0);

		else if (_strcmp(arg[j], "$") == 0)
			print_str(arg[j]);
/*
 *		else if (arg[j][0] == '$')
 *		{
 *			var = malloc(_strlen(arg[j]) - 1);
 *			if (var == NULL)
 *				exit (1);
 *			for (i = 1; arg[j][i]; ++i)
 *				var[i - 1] = arg[j][i];
 *			var[i - 1] = '\0';
 *
 *			val = _getenv(var, env);
 *			if (val)
 *				print_str(val);
 *
 *			free(var);
 *		}
 */
		else
			print_str(arg[j]);

		print_str(" ");
	}
	print_str("\n");
}
