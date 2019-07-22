#include "dog.h"
#include <stdlib.h>

/**
 * _strdup - create a copy of a string
 *
 * @str: string
 * Return: pointer to new string, or NULL
 */
char *_strdup(char *str)
{
	unsigned int length;
	char *new;

	/* check str */
	if (!str)
		return (NULL);
	for (length = 0; str[length]; length++)
		;
	/* allocate */
	new = malloc(length + 1);
	if (!new)
		return (NULL);
	/* copy */
	while (length--)
		new[length] = str[length];
	return (new);
}

/**
 * new_dog - for those who think dynamic memory allocation is acceptable
 *
 * @name: name (will be copied)
 * @age: age
 * @owner: owner (will be copied)
 * Return: pointer to new dog struct
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;

	if(!name || !owner)
		return (NULL);

	dog = malloc(sizeof(dog_t));
	if (!dog)
		return (NULL);

	dog->age = age;
	dog->name = _strdup(name);
	dog->owner = _strdup(owner);

	return (dog);
}
