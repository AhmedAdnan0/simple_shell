#include "func.h"

/**
 * creat_vec - ctreates an array of strings form a string
 * @cmd: input string
 * @delim: delimeter
 *
 * Return: pointer to the created array
 *         NULL --> IF FAILED
 */

char **creat_vec(char *cmd, char *delim)
{
	unsigned int i = 0;
	char *token, *cmd_cpy;
	char **vec;

	cmd_cpy = _strdup(cmd);

	token = strtok(cmd, delim);
	while (token)
	{
		token = strtok(NULL, delim);
		++i;
	}

	vec = malloc(i * sizeof(char *));
	if (vec == NULL)
		return (NULL);

	i = 0;
	token = strtok(cmd_cpy, delim);
	while (token)
	{
		vec[i] = token;
		token = strtok(NULL, delim);
		++i;
	}
	vec[i] = NULL;

	return (vec);
}

/**
 * path_dir - creates an array of path directories
 * @path: PATH value
 * @p_count: count of path directories
 *
 * Return: pointer to path directories
 */

char **path_dir(char *path, unsigned int *p_count)
{
	char *p, *path_cpy, **dir;
	unsigned int n = 0, i = 0;

	path_cpy = _strdup(path);

	p = strtok(path, ":");
	while (p)
	{
		++n;
		p = strtok(NULL, ":");
	}

	*p_count = n;

	dir = malloc(n * sizeof(char *));
	if (dir == NULL)
		exit(-1);

	p = strtok(path_cpy, ":");
	for (; i < n; ++i)
	{
		dir[i] = _strdup(p);
		_strcat(dir[i], "/");
		p = strtok(NULL, ":");
	}
	return (dir);
}

/**
 * path - return the argument as a path
 * @vec: commands passed to the shell
 * @dir: path directories
 * @n: no of path directories
 *
 * Return: nothing
 */

void path(char **vec, char **dir, unsigned int n)
{
	char *path;
	unsigned int i;
	struct stat st;

	if (stat(vec[0], &st) == 0)
		return;

	for (i = 0; i < n; ++i)
	{
		path = _strdup(dir[i]);
		_strcat(path, vec[0]);

		if (stat(path, &st) == 0)
		{
			vec[0] = path;
			return;
		}
	}
}

/**
 * main - command line interpreter
 * @argc: aruments count
 * @argv: arguments value
 * @env:  environment
 *
 * Return: 0 --> SUCCESS
 *        -1 --> FAILED
 */

int main(int argc, char **argv, char **env)
{
	char **vec, **dir, *cmd = NULL;
	unsigned int p_count = 0;
	int child, is_tty = isatty(STDIN_FILENO);
	struct stat st;

	if (argc != 1)
		return (-1);
	dir = path_dir(getenv("PATH"), &p_count);
	while (1)
	{
here:
		if (is_tty)
			print_str("#cisfun$ ");
		cmd = getcmd();
		vec = creat_vec(cmd, " \n");
		if (_strcmp(vec[0], "exit") == 0)
			break;
		else if (_strcmp(vec[0], "env") == 0)
		{
			print_env(env);
			goto here;
		}
		path(vec, dir, p_count);
		if (stat(vec[0], &st) == 0)
		{
			child = fork();
			if (child == -1)
				return (-1);
			if (child == 0)
				execve(vec[0], vec, env);
			else
				wait(NULL);
		}
		else
			print_err(argv[0], vec[0], is_tty);
		free(vec);
		if (is_tty == 0)
			break;
	}
	return (0);
}
