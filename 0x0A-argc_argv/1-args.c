#include <stdio.h>

/**
 * main - print number of arguments
 *
 * @argc: arg count
 * @argv: arg values
 * Return: 0
 */
int main(int argc, char *argv[])
{
	(void)argv;
	printf("%d\n", argc-1);
	return (0);
}
