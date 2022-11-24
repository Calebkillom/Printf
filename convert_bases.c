#include "main.h"


/**
 * convert_bases - converts numbers from decimal to any base
 *
 * @i: the number to convert
 * @tmp: the converted number as a string
 * @base: the base to convert the number to
 * @upper: switch for uppercase or lowercase digits
 * upper = 1: for uppercase digits
 * upper = 0: lowercase digits
 *
 * Return: nothing.
 */
void convert_bases(unsigned int i, char *tmp, int base, int upper)
{
	int d;
	char *str = tmp;

	while (i)
	{
		d = i % base;
		if (d > 9 && upper)
		{
			*str = 'A' + d - 10;
		}
		else if (d > 9 && !upper)
		{
			*str = 'a' + d - 10;
		}
		else
		{
			*str = '0' + d;
		}
		i /= base;
		str++;
	}

	*str = '\0';
	reverse_string(tmp);
}


/**
 * convert_bases2 - converts numbers from decimal (long) to any base
 * this function handles larger integers compared to the one above.
 * God, I wish C supported function overloading and default values :(
 *
 * @i: the number to convert
 * @tmp: the converted number as a string
 * @base: the base to convert the number to
 * @upper: switch for uppercase or lowercase digits
 * upper = 1: for uppercase digits
 * upper = 0: lowercase digits
 *
 * Return: nothing.
 */
void convert_bases2(unsigned long i, char *tmp, int base, int upper)
{
	int d;
	char *str = tmp;

	while (i)
	{
		d = i % base;
		if (d > 9 && upper)
		{
			*str = 'A' + d - 10;
		}
		else if (d > 9 && !upper)
		{
			*str = 'a' + d - 10;
		}
		else
		{
			*str = '0' + d;
		}
		i /= base;
		str++;
	}

	*str = '\0';
	reverse_string(tmp);
}
