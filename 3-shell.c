#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>

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

	cmd_cpy = strdup(cmd);

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

	path_cpy = strdup(path);

	p = strtok(path, ":");
	while (p)
	{
		++n;
		p = strtok(NULL, ":");
	}

	*p_count = n;

	dir = malloc(n * sizeof(char *));
	if (dir == NULL)
	{
		printf("Error: creating PTAH directories array\n");
		exit(-1);
	}

	p = strtok(path_cpy, ":");
	for (; i < n; ++i)
	{
		dir[i] = strdup(p);
		strcat(dir[i], "/");
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
		path = strdup(dir[i]);
		strcat(path, vec[0]);

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
	pid_t child;
	char *cmd = NULL;
	char **vec, **dir;
	size_t n = 0;
	struct stat st;
	unsigned int p_count = 0;

	dir = path_dir(getenv("PATH"), &p_count);

	while (1)
	{
		child = fork();
		if (child == -1)
			return (-1);

		if (child == 0)
		{
			while (1)
			{
				printf("#cisfun$ ");
				getline(&cmd, &n, stdin);

				vec = creat_vec(cmd, " \n");

				if (vec == NULL)
					return (-1);

				path(vec, dir, p_count);

			if (stat(vec[0], &st) == 0)
				execve(vec[0], vec, NULL);
			else
				printf("%s: No such file or directory\n", argv[0]);
			}
		}
		else
			wait(NULL);
	}

	return (0);
}
