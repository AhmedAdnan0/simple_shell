#include "func.h"

/**
 * _getenv - gets variable value from environ
 * @var: varuable
 * @env: environment
 *
 * Return: variable value
 */

char *_getenv(const char *var, char **env)
{
	char *token;
	int i = 0;

	while (env[i])
	{
		token = strtok(env[i], "=");

		if (_strcmp((char *)var, token) == 0)
		{
			token = strtok(NULL, "\n");
			return (token);
		}
		++i;
	}
	return (NULL);
}
