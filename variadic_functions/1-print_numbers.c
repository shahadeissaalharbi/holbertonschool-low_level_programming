#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_numbers - prints numbers separated by a string
 * @separator: string to print between numbers
 * @n: number of integers passed to the function
 * @...: the integers to print
 *
 * Return: Nothing.
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list args;

	va_start(args, n);
	for (i = 0; i < n; i++)
	{
		if (separator != NULL && i > 0)
			printf("%s", separator);
		printf("%d", va_arg(args, int));
	}
	va_end(args);
	printf("\n");
}
