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
	int separator;
	char c;
	int integer;
	float f;
	char *str;

	va_start(args, format);
	i = 0;
	separator = 0;
	while (format && format[i])
	{
		if (format[i] == 'c')
		{
			c = va_arg(args, int);
			if (separator)
				printf(", ");
			printf("%c", c);
			separator = 1;
		}
		if (format[i] == 'i')
		{
			integer = va_arg(args, int);
			if (separator)
				printf(", ");
			printf("%d", integer);
			separator = 1;
		}
		if (format[i] == 'f')
		{
			f = (float)va_arg(args, double);
			if (separator)
				printf(", ");
			printf("%f", f);
			separator = 1;
		}
		if (format[i] == 's')
		{
			str = va_arg(args, char *);
			if (separator)
				printf(", ");
			if (str == NULL)
				printf("(nil)");
			else
				printf("%s", str);
			separator = 1;
		}
		i++;
	}
	va_end(args);
	printf("\n");
}
