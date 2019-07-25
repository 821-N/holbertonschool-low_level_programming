/**
 * int_index - search int array for first matching item
 *  where @cmp(@array[index]) is not 0
 *
 * @array: array to search in
 * @size: size of @array
 * @cmp: test function
 * Return: matching index, or -1
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int index;

	if (!array || !cmp)
		return (-1);

	for (index = 0; index < size; index++)
		if (cmp(array[index]))
			return (index);
	return (-1);
}
