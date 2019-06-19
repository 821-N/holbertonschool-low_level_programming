#include <stdio.h>

#define print_size(size, n)\
	printf("Size of a" n " " #size ": %d byte(s)\n", (int)sizeof(size))

/**
 *main-main
 *Return:0
 */
int main(void)
{
	print_size(char, "");
	print_size(int, "n");
	print_size(long int, "");
	print_size(long long int, "");
	print_size(float, "");

	return (0);
}
