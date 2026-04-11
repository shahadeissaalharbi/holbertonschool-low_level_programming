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
			str = (t == 3) ? va_arg(args, char *) : NULL;
			if (sep)
				printf(", ");
			t == 0 ? printf("%c", va_arg(args, int)) :
			t == 1 ? printf("%d", va_arg(args, int)) :
			t == 2 ? printf("%f", va_arg(args, double)) :
			printf("%s", str ? str : "(nil)");
			sep = 1;
		}
		i++;
	}
	va_end(args);
	printf("\n");
}
