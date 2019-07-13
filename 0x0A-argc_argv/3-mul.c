#include <stdio.h>
#include <stdlib.h>

/**
 * main - multiply 2 numbers
 *
 * @argc: arg count
 * @argv: arg values
 * Return: 1 if there aren't enough args
 */
int main(int argc, char *argv[])
{
	if (argc < 3)
	{
		puts("Error");
		return (1);
	}
	printf("%d\n", atoi(argv[1]) * atoi(argv[2]));
	return (0);
}
