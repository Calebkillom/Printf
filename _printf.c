#include <stdio.h>
#include "main.h"

/**
  * _printf - produces output according to a format
  * @format: output format
  *
  * Return: number of characters printed
  */

int _printf(const char *format, ...)
{
	va_list args;
	//char *characters;
	unsigned int i = 0;
	int count = 0;
	int (*ptr)(va_list); //function pointer

	if (format == NULL)
		return (-1);

	va_start(args, format);
	
	while (format[i])
	{
		for (i = 0; format[i] != '\0' && format[i]; i++)
		{
			printchar(format[i]);
			count++;
		}

		if (!format[i])
			return (count);

		ptr = handle_specifiers(&format[i + 1]);

		if (ptr != NULL)
		{
			count += ptr(args);
			i += 2;
			continue;
		}

		if (!format[i + 1])
			return (-1);

		printchar(format[i]);
		count++;

		if (format[i +1] == '%')
			i += 2;
		else
			i++;
	}
	//printchar('\n');
	va_end(args);

	return (count);
}
