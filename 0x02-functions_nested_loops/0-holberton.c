#include "holberton.h"

/**
 * print - print to stdout
 * @message: string to print
 */
void print(char *message)
{
	while (*message)
		_putchar(*message++);
}

/**
 *main-main
 *Return:0
 */
int main(void)
{
	print("holberton\n");
	return (0);
}

