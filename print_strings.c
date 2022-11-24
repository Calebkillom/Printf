#include "main.h"

/**
  * _puts - prints a string
  * @str: string to print
  *
  * Return: no. characters printed
  */

int _puts(const char *str)
{
	int i;

	if (str == NULL)
		str = "(null)";

	for (i = 0; *(str + i) != '\0'; i++)
		printchar(*(str + i));

	return (i);
}

/**
  * handle_s - prints a string
  * @s: string to be printed
  *
  * Return: length of printed string
  */

int handle_s(va_list s)
{
	char *str = va_arg(s, char *);

	if (str == NULL)
		return (_puts("(null)"));

	return (_puts(str));
}

/**
 * handle_ascii - prints a string, including non printable characters.
 * The non printable characters are printed this way: \x,
 * followed by the ASCII code value in hexadecimal
 * (upper case - always 2 characters).
 *
 * @ascii: the string to be printed.
 * Return: the number of characters printed.
 */
int handle_ascii(va_list ascii)
{
	unsigned int i;
	char tmp[100];
	int count = 0;
	char *str = va_arg(ascii, char *);

	if (str == NULL)
	{
		return (_puts("(null)"));
	}

	for (i = 0; *(str + i); i++)
	{
		if (*(str + i) < 32 || *(str + i) >= 127)
		{
			_putchar('\\');
			_putchar('x');

			count += 2;
			convert_bases(*(str + i), tmp, 16, 1);

			if (_strlen(tmp) < 2)
				count += _putchar('0');

			count += _puts(tmp);
		}
		else
		{
			_putchar(*(str + i));
			count++;
		}
	}
	return (count);
}


/**
 * handle_r - prints a string in reverse.
 *
 * @r: the string to be printed.
 * Return: the number of characters printed.
 */
int handle_r(va_list r)
{
	char *str = va_arg(r, char *);
	int i, count = 0;

	if (str == NULL)
	{
		return (_puts("(null)"));
	}

	for (i = _strlen(str) - 1; i >= 0; i--)
	{
		count += _putchar(*(str + i));
	}

	return (count);
}


/**
 * handle_rot13 - prints a string encrypted by the ROT-13 cypher.
 *
 * @l: the string to be printed.
 * Return: the number of characters printed.
 */
int handle_rot13(va_list l)
{
	char tmp[1024];
	char *str = va_arg(l, char *);

	if (str == NULL)
	{
		return (_puts("(null)"));
	}

	_strcpy(tmp, str);

	return (_puts(rot13(tmp)));
}
