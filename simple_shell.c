#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * main - simple shell
 *
 * Return: 0
 */
int main(int argc, char **argv, char **envp)
{
	char *input = NULL;
	size_t n = 0;
	ssize_t check_gl;
	pid_t child;
	int status;
	int i = 0;

	if (argc < 1)
	{
		perror(argv[0]);
		return (1);
	}
	while(1)
	{
		print_str("#cisfun$ ");
		check_gl = getline(&input, &n, stdin);
		if (check_gl == -1)
		{
			perror("Error: can't read");
			exit(EXIT_FAILURE);
		}
		while (input[i] != '\n')
		{
			i++;
		}
		input[i] = '\0';
		if (_strcmp(input, "exit\n") == 0)
		{
			break;
		}
		child = fork();
		if (child == -1)
		{
			perror("forking");
			exit(EXIT_FAILURE);
		}
		else if (child == 0)
		{
			argv[0] = input;
			execve(input, argv, envp);
			perror("./shell");
			exit(EXIT_FAILURE);
		}
		else
			wait(&status);
	}
	free(input);
	return (0);
}
