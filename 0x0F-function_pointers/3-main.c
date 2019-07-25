#include <stdio.h>
#include "3-calc.h"
#include <stdlib.h>

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
		return(99);
	}

	res = f(atoi(argv[1]), atoi(argv[3]));

	printf("%d\n", res);
}
