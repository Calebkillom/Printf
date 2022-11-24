#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
  * struct specifier - handles specifier
  * @s: format to print
  * @ptr: pointer to formatting function
  */

typedef struct specifier
{
	char *s;
	int (*ptr)(va_list);
} format_specifiers;

int _printf(const char *format, ...);
int (*handle_specifiers(const char *format))(va_list);

int printchar(char c);
int handle_c(va_list c);

int _strlen(const char *str);
char *reverse_string(char *str);
char *_strcpy(char *dest, const char *src);
char *rot13(char *str);

/* implemented in convert_bases.c*/
void convert_bases(unsigned int i, char *tmp, int base, int upper);
void convert_bases2(unsigned long i, char *tmp, int base, int upper);

/* implemented in print_nums.c */
int handle_d(va_list d);
int handle_oct(va_list oct);
int handle_b(va_list b);
int handle_u(va_list u);

/* implemented in print_hex.c */
int handle_x(va_list x);
int handle_upper_x(va_list upper);
int handle_p(va_list p);

/* implemented in print_strings.c*/
int _puts(const char *str);
int handle_ascii(va_list ascii);
int handle_r(va_list r);
int handle_rot13(va_list l);
int handle_s(va_list s);

#endif
