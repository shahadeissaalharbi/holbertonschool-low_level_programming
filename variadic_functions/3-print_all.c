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
	char *types = "cifs";
	int t;

	va_start(args, format);
	i = 0;
	sep = 0;
	while (format && format[i])
	{
		t = 0;
		while (types[t] && types[t] != format[i])
			t++;
		if (types[t])
		{
			str = NULL;
			if (sep)
				printf(", ");
			sep = 1;
			if (t == 0)
				printf("%c", va_arg(args, int));
			if (t == 1)
				printf("%d", va_arg(args, int));
			if (t == 2)
				printf("%f", va_arg(args, double));
			if (t == 3)
			{
				str = va_arg(args, char *);
				printf("%s", str ? str : "(nil)");
			}
		}
		i++;
	}
	va_end(args);
	printf("\n");
}
