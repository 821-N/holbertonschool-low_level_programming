#include <stdio.h>
#include <stdlib.h>

/**
 * main - main. prints bytes from the compiled program
 *  are we supposed to ddescribe how to call the program here?
 *
 * @argc: argc
 * @argv: argv
 * Return: 0 (ok) 1 (wrong args) 2 (number is negative)
 */
int main(int argc, char **argv)
{
	int i, num;

	if (argc != 2)
	{
		printf("Error\n"); /* >:( */
		return (1);
	}
	num = atoi(argv[1]);
	if (num < 0)
	{
		printf("Error\n");
		return (2);
	}

	for (i = 0; i < num; i++)
	{
		if (i)
			printf(" ");
		printf("%02x", ((unsigned char *)main)[i]);
	}
	printf("\n");
	return (0);
}
