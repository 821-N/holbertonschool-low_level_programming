#include "3-calc.h"
#include <stdlib.h>

/**
 * get_op_func - get operator function given operator symbol
 *
 * @s: operator name
 * Return: operator function or NULL
 */
int (*get_op_func(char *s))(int, int)
{
	static op_t ops[] = { /* owo what's this */
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].op)
	{
		if (ops[i].op[0] == s[0])
			return (ops[i].f);
		i++;
	}
	return (NULL);
}
