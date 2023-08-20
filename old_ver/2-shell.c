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
	char *cmd = NULL, *delim = " \n";
	char **vec;
	ssize_t n = 0;
	struct stat st;

	while (1)
	{
		child = fork();
		if (child == -1)
			return (-1);

		if (child == 0)
		{
			printf("#cisfun$ ");
			getline(&cmd, &n, stdin);

			vec = creat_vec(cmd, delim);

			if (vec == NULL)
				return (-1);

			if (stat(vec[0], &st) == 0)
				execve(vec[0], vec, NULL);
			else
				printf("%s: No such file or directory\n", argv[0]);
		}
		else
			wait(NULL);
	}

	return (0);
}
