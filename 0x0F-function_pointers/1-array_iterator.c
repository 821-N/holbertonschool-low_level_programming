#include <stdlib.h>

/**
 * array_iterator - call a function for each item in an int array
 *
 * @array: int array
 * @size: number of items in @array
 * @action: function to call
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	while (size-- > 0)
		action(*array++);
}
