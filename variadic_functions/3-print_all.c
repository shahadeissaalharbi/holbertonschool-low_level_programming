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
	char tmp[50];

	va_start(args, format);
	i = 0;
	sep = 0;
	while (format && format[i])
	{
		str = NULL;
		tmp[0] = '\0';
		if (format[i] == 'c')
			sprintf(tmp, "%c", va_arg(args, int));
		if (format[i] == 'i')
			sprintf(tmp, "%d", va_arg(args, int));
		if (format[i] == 'f')
			sprintf(tmp, "%f", va_arg(args, double));
		if (format[i] == 's')
		{
			str = va_arg(args, char *);
			sprintf(tmp, "%s", str ? str : "(nil)");
		}
		if (tmp[0] != '\0')
		{
			if (sep)
				printf(", ");
			printf("%s", tmp);
			sep = 1;
		}
		i++;
	}
	va_end(args);
	printf("\n");
}
