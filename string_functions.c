#include "main.h"


/**
 * _strlen - finds the length of a string
 *
 * @str: the string whose length is to be found
 * Return: the length of the string.
 */
int _strlen(const char *str)
{
	int i = 0;

	while (*(str + i))
		i++;

	return (i);
}


/**
 * reverse_string - reverses a string
 *
 * @str: the string to be reversed.
 * Return: a pointer to the reversed string.
 */
char *reverse_string(char *str)
{
	char *t = str;
	char n[1024];
	short c = 0;

	while (*str != '\0')
	{
		n[c] = *str;
		str++;
		c++;
	}
	c = 0;

	while (str > t)
	{
		str--;
		*str = n[c];
		c++;
	}
	return (str);
}


/**
 * _strcpy - copies a string
 *
 * @dest: destination (the new copy of string src)
 * @src: source (the string to be copied)
 * Return: pointer to the copy of src string
 */
char *_strcpy(char *dest, const char *src)
{
	int i;

	for (i = 0; *(src + i) != '\0'; i++)
	{
		*(dest + i) = *(src + i);
	}
	dest[i] = '\0';

	return (dest);

}


/**
 * rot13 - rotates characters of a string by 13 places.
 * It encrypts a string a string using the ROT-13 cypher.
 *
 * @str: the string to be encrypted.
 * Return: encrypted string.
 */
char *rot13(char *str)
{
	int i, j;
	char *a = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *b = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	for (i = 0; *(str + i); i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (*(a + j) == *(str + i))
			{
				*(str + i) = *(b + j);
				break;
			}
		}
	}
	return (str);
}
