#include "func.h"

/**
* _strlen - returns string length
* @s: string to be checked
*
* Return: string length
*/

int _strlen(char *s)
{
	int i = 0;

	while (*(s + i) != '\0')
	{
		++i;
	}
	return (i);
}
