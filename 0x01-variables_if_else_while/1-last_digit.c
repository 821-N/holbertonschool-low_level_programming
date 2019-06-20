#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 *main--
 *Return:0
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	char last = n % 10;
	printf("Last digit of %d is %d and is ", n, last);
	if (last > 5)
		printf("greater than 5");
	else if(last == 0)
		printf("0");
	else
		printf("less than 6 and not 0");
	printf("\n");
	
	return (0);
}
