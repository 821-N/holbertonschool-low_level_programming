#include "dog.h"
#include <stdio.h>

/**
 * print_or_nil - printf(@format, @str), unless @str is NULL
 *
 * @format: printf format, containing 1 %s
 * @str: string or NULL
 */
void print_or_nil(char *format, char *str)
{
	if (str)
		printf(format, str);
	else
		printf(format, "(nil)");
}

/**
 * print_dog - print a dog struct in the form:
 *  Name: <.name>
 *  Age: <.age %.6f>
 *  Owner: <.owner>
 *
 * Use (nil) if name/owner is NULL. if @d is null, print nothing
 *
 * @d: ptr to dog struct
 */
void print_dog(struct dog *d)
{
	if (!d)
		return;
	print_or_nil("Name: %s\n", d->name);
	printf("Age: %f\n", d->age);
	print_or_nil("Owner: %s\n", d->owner);
}
