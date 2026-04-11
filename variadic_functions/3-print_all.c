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
	double f;
	char *str;
	const char *types = "cifs";
	int t;

	va_start(args, format);
	i = 0;
	separator = 0;
	while (format && format[i])
	{
		t = 0;
		while (types[t] && types[t] != format[i])
			t++;
		if (types[t] && separator)
			printf(", ");
		if (format[i] == 'c')
		{
			c = va_arg(args, int);
			printf("%c", c);
			separator = 1;
		}
		else if (format[i] == 'i')
		{
			integer = va_arg(args, int);
			printf("%d", integer);
			separator = 1;
		}
		else if (format[i] == 'f')
		{
			f = va_arg(args, double);
			printf("%f", f);
			separator = 1;
		}
		else if (format[i] == 's')
		{
			str = va_arg(args, char *);
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
