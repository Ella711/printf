#include "main.h"
/**
 * check_buffer_length - if it goes over buffer length
 * it'll print everything in current buffer and revert back to 0
 *@buffer: buffer to hold string to print
 *@length: length/position of buffer
 * Return: a string
 */
int check_buffer_length(char *buffer, int length)
{
	if (length > 1020)
	{
		write(1, buffer, length);
		length = 0;
	}
	return (length);
}

/**
 * create_buffer - creates the memory allocation for buffer pointer
 * Return: a string pointer
 */
char *create_buffer(void)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
		return (NULL);
	return (buffer);
}
/**
 * write_buffer - prints what's saved in the buffer
 *@buffer: string of what's to be printed
 *@length: length of string/buffer
 *@arguements: valist
 */
void write_buffer(char *buffer, int length, va_list arguements)
{
	char *buffr;

	buffr = realloc(buffer, length);

	write(1, buffr, length);
	free(buffr);
	va_end(arguements);
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
		{0, NULL}
	};

	for (i = 0; choice[i].func; i++)
	{
		if (choice[i].specifier == S)
			return (choice[i].func);
	}
	return (NULL);
}

