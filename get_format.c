#include "main.h"
/**
 * print_char - prints a char
 * @list: variadic list
 * Return: char
 */
int print_char(va_list list)
{
	char c;

	c = va_arg(list, int);

	if (c == 0)
		c = '\0';

	return (_putchar(c));
}
/**
 * print_int - prints an int
 * @list: va list
 * Return: int
 */
int print_int(va_list list)
{
	_putchar(va_arg(list, int));

	return (0);
}
/**
 * print_string - prints a string
 * @list: va list
 * Return: 0
 */
int print_string(va_list list)
{
	char *s;

	s = va_arg(list, char *);
	if (s == NULL)
		s = "(null)";

	while (*s)
	{
		_putchar(*s);
		s++;
	}
	return (0);
}

