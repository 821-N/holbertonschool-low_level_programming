#include <stdio.h>
#include <stdlib.h>

/**
 * main - calculate number of coins needed to get the value passed.
 *  coins are 25, 10, 5, 2???, and 1 cent.
 *
 * @argc: arg count
 * @argv: arg values
 * Return: error
 */
int main(int argc, char *argv[])
{
	int cents, coins = 0;

	if (argc != 2)
	{
		puts("Error");
		return (1);
	}
	cents = atoi(argv[1]);
	while (1)
	{
		if (cents >= 25)
			cents -= 25;
		else if (cents >= 10)
			cents -= 10;
		else if (cents >= 5)
			cents -= 5;
		else if (cents >= 2)
			cents -= 2;
		else if (cents >= 1)
			cents -= 1;
		else
			break;

		coins++;
	}
	printf("%d\n", coins);
	return (0);
}
