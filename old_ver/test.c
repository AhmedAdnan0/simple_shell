#include <stdio.h>
#include <unistd.h>
#include <string.h>

char *getcmd();

int main()
{
	char *cmd = getcmd();

	printf("buffer ==> %s", cmd);
	printf("size = %ld\n", sizeof(cmd));
	return (0);

}
/**
 * getcmd - get command line
 *
 * Return: cmd line
 */

char *getcmd()
{
	char buffer[1024];
	int r;

	r = read(STDIN_FILENO, buffer, sizeof(buffer));
	if (r == -1)
		return (NULL);

	return(_strdup(buffer));
}


