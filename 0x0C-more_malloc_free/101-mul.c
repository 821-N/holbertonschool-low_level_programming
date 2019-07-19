#include <stdlib.h>
#include <stdio.h>

/**
 * add2 - add a number to a big endian decimal string
 *
 * @res: string to add to
 * @num: number to add
 */
void add2(char *res, int num)
{
	int sum = *res - '0' + num;

	/* printf("adding %d to %d, result is %d\n", num, *res - '0', sum); */
	*res = sum % 10 + '0';
	if (sum / 10)
		add2(res - 1, sum / 10);
}

/**
 * strnumlen - get length of decimal string
 *
 * @s: string
 * Return: length of @s, or 0 if @s contains any non-digit chars
 */
int strnumlen(char *s)
{
	int length = 0;

	for (; *s; s++, length++)
		if (*s < '0' || *s > '9')
			return (0);

	return (length);
}

/**
 * fail_if - exit if @c is true
 *
 * @c: condition
 */
void fail_if(int c)
{
	if (c)
	{
		printf("Error\n");
		exit(98);
	}
}

/**
 * main - multiply 2 numbers
 *
 * @argc: number of args
 * @argv: args
 * Return: 0
 */
int main(int argc, char **argv)
{
	int len1, len2, i, j;
	char *sum;

	/* check inputs */
	fail_if(argc != 3);
	len1 = strnumlen(argv[1]);
	len2 = strnumlen(argv[2]);
	fail_if(!len1 || !len2);
	/* create sum array */
	sum = malloc(len1 + len2 + 1);
	fail_if(!sum);
	for (i = 0; i < len1 + len2; i++)
		sum[i] = '0';
	sum[i] = '\0';
	/* multiply */
	for (j = len2 - 1; j >= 0; j--)
		for (i = len1 - 1; i >= 0; i--)
			add2(sum + i + j + 1, (argv[1][i] - '0') * (argv[2][j] - '0'));
	/* skip leading zeroes and print */
	for (i = 0; sum[i] == '0'; i++)
		;
	if (!sum[i])
		i--;
	puts(sum + i);
	/* exit */
	free(sum);
	return (0);
}
