#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/**
 * main - outputs a random string with an ascii sum of 2772
 * Return: 0
 */
int main(void)
{
	short sum = 0;
	char random;

	srand(time(0));

	while (sum < 2772)
	{
		do
			random = ' ' + rand() % ('~' - ' ' + 1);
		while (sum + random != 2772 && sum + random + 32 > 2772);
		sum += random;
		putchar(random);
	}
	return (0);
}
