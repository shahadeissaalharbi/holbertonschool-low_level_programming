#include "main.h"

/**
 * leet - encodes a string into 1337
 * @s: pointer to the string to encode
 *
 * Return: pointer to the modified string
 */
char *leet(char *s)
{
	int i;
	int j;
	char upper[] = "AaEeOoTtLl";
	char leet_r[] = "4433007711";

	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (upper[j] != '\0')
		{
			if (s[i] == upper[j])
				s[i] = leet_r[j];
			j++;
		}
		i++;
	}
	return (s);
}
