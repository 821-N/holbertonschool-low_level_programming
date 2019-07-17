#include <stdlib.h>

/**
 * free_grid - free grid created by alloc_grid
 *
 * @grid: grid
 * @height: number of rows in @grid
 */
void free_grid(int **grid, int height)
{
	int i;

	if (!grid)
		return;
	for (i = 0; i < height; i++)
		if (grid[i])
			free(grid[i]);
	free(grid);
}
