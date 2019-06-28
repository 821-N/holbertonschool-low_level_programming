#include <stdio.h>

/**
 * main - fizz buzz
 * Return: 0
 */
int main(void)
{
	int i;

	for (i = 1; i <= 100; i++)
	{
		if (i > 1)
			putchar(' ');

		if (i % 3 == 0)
			printf("Fizz");
		if (i % 5 == 0)
			printf("Buzz");
		if (i % 3 && i % 5)
			printf("%d", i);
	}
	putchar('\n');

	return (0);
}
