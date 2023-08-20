#include "func.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_str - print a char string
 * @str: string to be printed
 */

void print_str(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; ++i)
		_putchar(str[i]);
}

/**
 * print_int - prints int
 * @x: intiger
 */

void print_int(int x)
{
	unsigned int y;

	if (x < 0)
	{
		_putchar('-');
		y = -1 * x;
	}
	else
		y = x;

	if (y / 10 != 0)
		print_int(y / 10);

	_putchar('0' + y % 10);
}

/**
 * print_env - prints environment
 * @env: environment
 */

void print_env(char **env)
{
	int i;

	if (env == NULL)
		return;

	for (i = 0; env[i]; ++i)
	{
		print_str(env[i]);
		_putchar('\n');
	}
}
