#include "func.h"

/**
 * _realloc - reallocates the memory to a new size
 * @ptr: old memory location
 * @old_size: old memory size
 * @new_size: new memory size
 *
 * Return: new location of memory
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *old_ptr, *new_ptr;
	unsigned int i;

	if (old_size == new_size && ptr != NULL)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (old_size == 0 || ptr == NULL)
	{
		new_ptr = malloc(new_size);
		if (new_ptr == NULL)
			return (NULL);
		return (new_ptr);
	}

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	old_ptr = ptr;

	for (i = 0; i < new_size && i < old_size; ++i)
		new_ptr[i] = old_ptr[i];

	free(ptr);
	return (new_ptr);
}
