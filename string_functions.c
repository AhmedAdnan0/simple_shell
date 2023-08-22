#include "func.h"

/**
 * _strcmp - compare two strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 0 if equal
 *         else otherwise
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		++i;

	if (s1[i] == s2[i])
		return (0);
	else
		return (s1[i] - s2[i]);
}

/**
 * _strcat - concatenates two strings.
 * @dest: destinantion
 * @src: source
 *
 * Return: dest after concatination
 */

char *_strcat(char *dest, char *src)
{
	int i, j;

	for (j = 0; dest[j] != '\0'; ++j)
	{
	}
	for (i = 0; src[i] != '\0'; ++i)
		*(dest + j + i) = *(src + i);
	*(dest + j + i) = '\0';

	return (dest);
}

/**
 * _strdup - creates a pointer to a new string
 * @str: string to be copied
 *
 * Return: a pointer to the newstring
 */

char *_strdup(char *str)
{
	int i;
	char *new_str;

	for (i = 0; str[i] != '\0'; ++i)
	{
	}
	new_str = malloc(i * sizeof(char));
	if (new_str == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; ++i)
		new_str[i] = str[i];
	new_str[i] = '\0';

	return (new_str);
}

/**
 * _memset - fills the first n bytes of the memory area
 * @str: string
 * @c: filler
 * @n: size
 *
 * Return: str
 */

char *_memset(char *str, char c, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; ++i)
		str[i] = c;

	return (str);
}

/*
 * _atoi - converts str to string
 * @str: string to be converted
 *
 * Return: number
 */

int _atoi(char *str)
{
	int i = 0, res = 0, sign = 1;

	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}

	for (; str[i] != '\0'; i++)
		res = res * 10 + str[i] - '0';

	return (sign * res);
}
