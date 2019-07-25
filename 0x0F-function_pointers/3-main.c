#include <stdio.h>
#include "3-calc.h"
#include <stdlib.h>

/**
 * main - main
 *
 * do an operation on 2 numbers
 * a <number1> <op> <number2>
 * @argc: arg count
 * @argv: args
 * Return: 98 = wrong number of args, 99 = invalid op, 100 = div by 0
 */
int main(int argc, char **argv)
{
	int (*f)(int a, int b);
	int res;

	if (argc != 3 + 1)
	{
		puts("Error");
		return (98);
	}

	f = get_op_func(argv[2]);
	if (!f)
	{
		puts("Error");
		return (99);
	}

	res = f(atoi(argv[1]), atoi(argv[3]));

	printf("%d\n", res);

	return (0);
}
