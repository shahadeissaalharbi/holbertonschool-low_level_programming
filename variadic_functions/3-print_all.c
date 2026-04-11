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
	char c;
	int n;
	double f;

	va_start(args, format);
	i = 0;
	sep = 0;
	while (format && format[i])
	{
		str = NULL;
		c = (format[i] == 'c') ? (char)va_arg(args, int) : 0;
		n = (format[i] == 'i') ? va_arg(args, int) : 0;
		f = (format[i] == 'f') ? va_arg(args, double) : 0;
		if (format[i] == 's')
			str = va_arg(args, char *);
		if (format[i] == 'c' && ++sep)
			printf("%s%c", sep > 1 ? ", " : "", c);
		if (format[i] == 'i' && ++sep)
			printf("%s%d", sep > 1 ? ", " : "", n);
		if (format[i] == 'f' && ++sep)
			printf("%s%f", sep > 1 ? ", " : "", f);
		if (format[i] == 's' && ++sep)
			printf("%s%s", sep > 1 ? ", " : "", str ? str : "(nil)");
		i++;
	}
	va_end(args);
	printf("\n");
}
