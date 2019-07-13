#include <stdio.h>
#include <stdlib.h>

/**
 * readnum - read positive integer from string
 * 
 * @s: string
 * Return: number, or -1 if string contained non-digits
 */
int readnum(char *s)
{
	int num = 0;
	
	for (; *s; s++)
		if(*s >= '0' && *s <= '9')
			num = num * 10 + (*s - '0');
		else
			return (-1);
	return (num);
}

/**
 * main - add numbers
 *
 * @argc: arg count
 * @argv: arg values
 * Return: 1 if any args aren't numbers
 */
int main(int argc, char **argv)
{
	int x, sum = 0;

	argv++;
	for ((void)argc; *argv; argv++)
	{
		x = readnum(*argv);
		if (x < 0)
		{
			puts("Error");
			return (1);
		}
		sum += x;
	}
	printf("%d\n", sum);
	return (0);
}
