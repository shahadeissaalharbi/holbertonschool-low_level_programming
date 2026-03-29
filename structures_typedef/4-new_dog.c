#include <stdlib.h>
#include "dog.h"

/**
 * _strlen - returns the length of a string
 * @s: the string to measure
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;

	return (i);
}

/**
 * _strcpy - copies a string into a new allocated space
 * @s: the string to copy
 *
 * Return: a pointer to the new string, or NULL if it fails
 */
char *_strcpy(char *s)
{
	char *copy;
	int len;
	int i;

	len = _strlen(s);
	copy = malloc(sizeof(char) * (len + 1));
	if (copy == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		copy[i] = s[i];

	return (copy);
}

/**
 * new_dog - creates a new dog
 * @name: the name of the dog
 * @age: the age of the dog
 * @owner: the owner of the dog
 *
 * Return: a pointer to the new dog, or NULL if it fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;

	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);

	dog->name = _strcpy(name);
	if (dog->name == NULL)
	{
		free(dog);
		return (NULL);
	}

	dog->owner = _strcpy(owner);
	if (dog->owner == NULL)
	{
		free(dog->name);
		free(dog);
		return (NULL);
	}

	dog->age = age;

	return (dog);
}
