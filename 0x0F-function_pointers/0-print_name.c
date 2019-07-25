/**
 * print_name - passes @name to function @f
 *
 * @name: name
 * @f: function to call
 */
void print_name(char *name, void (*f)(char *))
{
	f(name);
}
