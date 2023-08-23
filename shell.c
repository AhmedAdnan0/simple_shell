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

	vec = malloc(i * 4);
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

	dir = malloc(n * 4);
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
 * Return: command path
 */

char *path(char *vec, char **dir, unsigned int n)
{
	char *path;
	unsigned int i;
	struct stat st;

	if (stat(vec, &st) == 0)
		return (_strdup(vec));

	for (i = 0; i < n; ++i)
	{
		path = _strdup(dir[i]);
		_strcat(path, vec);

		if (stat(path, &st) == 0)
			return (path);
	}
	return (_strdup(vec));
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
	char **vec, **dir, *cmd_path, *cmd = NULL;
	unsigned int p_count = 0;
	int counter = 0, child, is_tty, exit_status = 0;
	struct stat st;
	size_t n = 0;

	is_tty = isatty(STDIN_FILENO);
	if (argc != 1)
		return (-1);
	dir = path_dir(_getenv("PATH", env), &p_count);
	while (1)
	{
here:
		counter++;
		if (is_tty)
			print_str("#cisfun$ ");
		getline(&cmd, &n, stdin);
		comment_handler(&cmd);
		vec = creat_vec(cmd, " \n\t");
		if (_strcmp(vec[0], "exit") == 0)
			break;
		else if (_strcmp(vec[0], "env") == 0)
		{
			print_env(env);
			goto here;
		}
		else if (_strcmp(vec[0], "echo") == 0)
		{
			echo(vec);
			goto here;
		}
		cmd_path = path(vec[0], dir, p_count);
		if (stat(cmd_path, &st) == 0)
		{
			child = fork();
			if (child == -1)
				return (-1);
			if (child == 0)
				execve(cmd_path, vec, env);
			else
				wait(NULL);
		}
		else
			print_err(argv[0], vec[0], counter, 1);
		free(vec);
		if (is_tty == 0)
			break;
	}
	if (vec[1])
	{
		exit_status = _atoi(vec[1]);
		if (exit_status < 0)
		{
			print_err(argv[0], vec[0], counter, 2);
			print_str_err(vec[1]);
			print_str_err("\n");
			goto here;
		}
	}
	free(vec);
	exit(exit_status);
}
