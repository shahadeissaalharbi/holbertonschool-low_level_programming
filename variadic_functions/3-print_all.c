#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_all - prints anything based on format string
 * @format: list of types of arguments
 * @...: the arguments to print
 *
 * Return: Nothing.
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i;
	int sep;
	char *str;

	va_start(args, format);
	i = 0;
	sep = 0;
	while (format && format[i])
	{
		str = NULL;
		if (format[i] == 'c')
		{
			if (sep)
				printf(", ");
			printf("%c", va_arg(args, int));
			sep = 1;
		}
		if (format[i] == 'i')
		{
			if (sep)
				printf(", ");
			printf("%d", va_arg(args, int));
			sep = 1;
		}
		if (format[i] == 'f')
		{
			if (sep)
				printf(", ");
			printf("%f", va_arg(args, double));
			sep = 1;
		}
		if (format[i] == 's')
		{
			str = va_arg(args, char *);
			if (sep)
				printf(", ");
			printf("%s", str ? str : "(nil)");
			sep = 1;
		}
		i++;
	}
	va_end(args);
	printf("\n");
}
