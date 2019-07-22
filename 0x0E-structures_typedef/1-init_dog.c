#include "dog.h"

/**
 * init_dog - for those who refuse to use struct initializers
 *
 * @d: pointer to struct
 * @name: d.name
 * @age: d.age
 * @owner: d.owner
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (!d)
		return;
	d->name = name;
	d->age = age;
	d->owner = owner;
}
