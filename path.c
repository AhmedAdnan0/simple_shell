#include "func.h"

/**
 * path_dir - creates an array of path directories
 * @path: PATH value
 * @n: count of path directories
 *
 * Return: pointer to path directories
 */

char **path_dir(char *path, int *dir_n)
{
printf("from path functiom");
	char *p, **dir;
	int i = 0, n = 0;

printf("from path functiom");
	for (; path[i]; ++i)
		if (path[i] == ':')
			++n;
	if (n == 0)
		exit(-1);
	++n;
	*dir_n = n;
	
	dir = malloc(n * sizeof(char *));
	if (dir == NULL)
		exit(-1);

	p = strtok(path, ":");
	while (p)
		p = strtok(NULL, ":");

	for (i = 0; i < n; ++i)
	{
		dir[i] = strdup(p);
		strcat(dir[i], "/");
		p = strtok(NULL, ":");
	}
	dir[i] = NULL;
	return (dir);
}

int main(void)
{
	int n = 0;
	char *path = "bin/usr:asd:asdas";
	char **dir;

	printf("%s\n", path);
	printf("1\n");
	dir = path_dir(path, &n);

	for (int i = 0; i < n; ++i)
	{
//		print_str(dir[i]);
//		_putchar('\n');
		printf("%s\n", dir[i]);
	}
	return(0);
}
