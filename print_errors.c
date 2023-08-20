#include "func.h"

/**
 * _putchar_err - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar_err(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_str_err - print a char string to stderr
 * @str: string to be printed
 */

void print_str_err(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; ++i)
		_putchar_err(str[i]);
}

/**
 * print_int_err - prints int to stderr
 * @x: intiger
 */

void print_int_err(int x)
{
	unsigned int y;

	if (x < 0)
	{
		_putchar_err('-');
		y = -1 * x;
	}
	else
		y = x;

	if (y / 10 != 0)
		print_int_err(y / 10);

	_putchar_err('0' + y % 10);
}

/**
 * print_err - prints error message
 * @sh: program name
 * @cmd: command
 * @counter: cmd count
 * @errno: error code
 */

void print_err(char *sh, char *cmd, int counter, int errno)
{
	switch (errno)
	{
		case 1:			/* command not found */
			print_str_err(sh);
			print_str_err(": ");
			print_int_err(counter);
			print_str_err(": ");
			print_str_err(cmd);
			print_str_err(": not found\n");
			break;
	}
}
