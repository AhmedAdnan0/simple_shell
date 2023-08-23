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
	char *token, *env_cpy;
	int i = 0;

	while (env[i])
	{
		env_cpy = _strdup(env[i]);
		token = strtok(env_cpy, "=");

		if (_strcmp((char *)var, token) == 0)
		{
			token = strtok(NULL, "\n");
			return (token);
		}
		++i;
		free(env_cpy);
	}
	return (NULL);
}
