#include "main.h"
/**
 * _printf - prints
 * @format: list of what needs to be printed
 * Return: int
 */
int _printf(const char *format, ...)
{
	const char *format_pointer = format;
	va_list list;

	va_start(list, format);

	while (*format_pointer && *format)
	{
		if (*format_pointer != '%')
		{
			_putchar(*format_pointer);
			format_pointer++;
			continue;
		}
		format_pointer++;
		switch (*format_pointer)
		{
			case 'c':
				print_char(list);
				break;
			case 's':
				print_string(list);
				break;
			case 'd':
				print_int(list);
				break;
			default:
				format_pointer++;
				continue;
		}
		format_pointer++;
	}
	va_end(list);
	return (0);
}

