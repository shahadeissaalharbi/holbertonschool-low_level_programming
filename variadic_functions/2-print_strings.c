#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_strings - prints strings separated by a string
 * @separator: string to print between strings
 * @n: number of strings passed to the function
 * @...: the strings to print
 *
 * Return: Nothing.
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	char *str;
	va_list args;

	va_start(args, n);
	for (i = 0; i < n; i++)
	{
		if (separator != NULL && i > 0)
			printf("%s", separator);
		str = va_arg(args, char *);
		if (str == NULL)
			printf("(nil)");
		else
			printf("%s", str);
	}
	va_end(args);
	printf("\n");
}
