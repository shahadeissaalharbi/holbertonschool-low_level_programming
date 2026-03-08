#include "main.h"
#include <stddef.h>

/**
 * _strstr - locates a substring
 * @haystack: the string to search in
 * @needle: the substring to find
 *
 * Return: pointer to the beginning of the located substring,
 * or NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
	unsigned int i;
	unsigned int j;

	if (needle[0] == '\0')
		return (haystack);
	i = 0;
	while (haystack[i] != '\0')
	{
		j = 0;
		while (haystack[i + j] == needle[j] && needle[j] != '\0')
			j++;
		if (needle[j] == '\0')
			return (haystack + i);
		i++;
	}
	return (NULL);
}
