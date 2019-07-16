#include <stdlib.h>

/**
 * alloc_row - allocate and initialize int array
 *
 * @length: number of items
 * Return: pointer to array, or NULL
 */
int *alloc_row(int length)
{
	int *ret = malloc(length * sizeof(int));
	int i;

	if (ret)
		for (i = 0; i < length; i++)
			ret[i] = 0;
	return (ret);
}

/**
 * alloc_grid - allocate an array of pointers to arrays, filled with 0.
 *
 * @width: size of rows
 * @height: number of rows
 * Return: pointer to array, or NULL
 */
int **alloc_grid(int width, int height)
{
	int **ret;
	int i;

	if (width <= 0 || height <= 0)
		return (NULL);
	ret = malloc(height * sizeof(int *));
	if (!ret)
		return (NULL);
	for (i = 0; i < height; i++)
	{
		ret[i] = alloc_row(width);
		if (!ret[i])
		{
			/* free everything */
			while (i > 0)
				free(ret[--i]);
			free(ret);
			return (NULL);
		}
	}
	return (ret);
}
