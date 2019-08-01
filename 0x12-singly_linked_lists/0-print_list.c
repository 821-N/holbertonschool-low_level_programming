#include "lists.h"

/**
 * print_number_sub - magic recursive printer
 *
 * @n: number
 */
void print_number_sub(unsigned int n)
{
	if (!n)
		return;
	print_number_sub(n / 10);
	n %= 10;
	_putchar('0' + n);
}

/**
 * print_number - print number
 *
 * @n: number to print
 */
void print_number(unsigned int n)
{
	if (n)
		print_number_sub(n);
	else
		_putchar('0');
}

void print_item(char *s, unsigned int len)
{
	unsigned int i;

	if (!s)
		len = 0;

	_putchar('[');
	print_number(len);
	_putchar(']');
	_putchar(' ');

	if (!s)
	{
		s = "(nil)";
		len = 5;
	}
	for (i = 0; i < len; i++)
		_putchar(s[i]);
	_putchar('\n');
}

size_t print_list(const list_t *h)
{
	if (!h)
		return (0);
	print_item(h->str, h->len);
	return (1 + print_list(h->next));

}
