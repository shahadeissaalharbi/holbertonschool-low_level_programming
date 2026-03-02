#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: pointer to the string to convert
 *
 * Return: the integer value of the string
 */
int _atoi(char *s)
{
	int sign;
	int result;
	int i;

	sign = 1;
	result = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			result = result * 10 + (s[i] - '0');
			while (s[i + 1] >= '0' && s[i + 1] <= '9')
			{
				i++;
				result = result * 10 + (s[i] - '0');
			}
			return (sign * result);
		}
		i++;
	}
	return (0);
}
