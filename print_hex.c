#include "main.h"


/**
 * handle_x - prints lowercase hexadecimals
 *
 * @x: the number to be printed in hexadecimal
 * Return: the count of the digits printed.
 */
int handle_x(va_list x)
{
	char tmp[100];
	int num = 0;

	num = va_arg(x, unsigned int);

	if (num == 0)
	{
		return (_puts("0"));
	}
	convert_bases(num, tmp, 16, 0);

	return (_puts(tmp));
}


/**
 * handle_upper_x - prints uppercase hexadecimals
 *
 * @upper: the number to be printed in hexadecimal
 * Return: the count of the digits printed.
 */
int handle_upper_x(va_list upper)
{
	char tmp[100];
	int num = 0;

	num = va_arg(upper, unsigned int);

	if (num == 0)
	{
		return (_puts("0"));
	}
	convert_bases(num, tmp, 16, 1);

	return (_puts(tmp));
}


/**
 * handle_p - prints addresses of variables
 *
 * @p: the address to be printed
 * Return: the count of the printed digits of the address.
 */
int handle_p(va_list p)
{
	char tmp[100];
	int count = 0;
	unsigned long num = 0;

	num = va_arg(p, unsigned long);

	if (num == 0)
	{
		return (_puts("(nil)"));
	}

	convert_bases2(num, tmp, 16, 0);
	count += _puts("0x");
	count += _puts(tmp);

	return (count);
}
