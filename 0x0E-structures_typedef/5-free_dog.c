#include "dog.h"
#include <stdlib.h>

/**
 * free_dog - free dog struct
 *  This asssumes the name/owner are dynamically allocated(!)
 *
 * @d: dog struct to free
 */
void free_dog(dog_t *d)
{
	if (!d)
		return;
	free(d->name);
	free(d->owner);
	free(d);
}
