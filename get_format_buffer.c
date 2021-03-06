#include "main.h"

/**
 * create_buffer - creates the memory allocation for buffer pointer
 * Return: a string pointer
 */

char *create_buffer(void)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 2048);
	if (buffer == NULL)
		return (NULL);
	return (buffer);
}

/**
 * write_buffer - prints what's saved in the buffer
 *@buffer: string of what's to be printed
 *@length: length of string/buffer
 *@arguments: valist
 */

void write_buffer(char *buffer, int length, va_list arguments)
{
	char *buffr;

	buffr = realloc(buffer, length);

	write(1, buffr, length);
	free(buffr);
	va_end(arguments);
}

/**
 * get_spec_func - looks and returns required function
 * @S: char format specifier
 * Return: function needed
 */

char* (*get_spec_func(char S))(va_list)
{
	int i;

	format_spec choice[] = {
		{'c', print_char},
		{'s', print_string},
		{'i', print_integer},
		{'d', print_integer},
		{0, NULL}
	};

	for (i = 0; choice[i].func; i++)
	{
		if (choice[i].specifier == S)
			return (choice[i].func);
	}
	return (NULL);
}

