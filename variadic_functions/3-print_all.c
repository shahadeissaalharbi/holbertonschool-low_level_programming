#include <stdio.h>
#include <string.h>
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
	char *types = "cifs";

	va_start(args, format);
	i = 0;
	sep = 0;
	while (format && format[i])
	{
		str = NULL;
		if (strchr(types, format[i]))
		{
			if (sep)
				printf(", ");
			if (format[i] == 'c')
				printf("%c", va_arg(args, int));
			if (format[i] == 'i')
				printf("%d", va_arg(args, int));
			if (format[i] == 'f')
				printf("%f", va_arg(args, double));
			if (format[i] == 's')
			{
				str = va_arg(args, char *);
				printf("%s", str ? str : "(nil)");
			}
			sep = 1;
		}
		i++;
	}
	va_end(args);
	printf("\n");
}
