/**
 * swap_int - swap the values of 2 integers
 *
 * @a: int 1
 * @b: int 2
 */
void swap_int(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}
