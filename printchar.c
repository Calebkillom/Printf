#include <unistd.h>
#include "main.h"

/**
  * printchar - prints characters to std out
  * @c: character to be printed
  *
  * Return: on success 1
  */

int printchar(char c)
{
	return (write(1, &c, 1));
}

/**
  * handle_c - prints a character
  * @c: character to be printed
  *
  * Return: always 1
  */

int handle_c(va_list c)
{
	char character = (char) va_arg(c, int);
	
	return(printchar(character));
}
