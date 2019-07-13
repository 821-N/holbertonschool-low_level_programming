#include <stdio.h>

/**
 * main - print arguments
 *
 * @argc: arg count
 * @argv: arg values
 * Return: 0
 */
int main(int argc, char *argv[])
{
	for ((void)argc; *argv; argv++)
		puts(*argv);
	return (0);
}
