#include "main.h"

int check_buffer_length(char *buffer, int length)
{
	if (length > 1020)
	{
		write(1, buffer, length);
		length = 0;
	}
	return (length);
}

char *create_buffer(void)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
        	return (NULL);
	return (buffer);
}

void write_buffer(char *buffer, int length, va_list arguements)
{
	char *buffr;

	buffr = realloc(buffer, length);
	
	write(1, buffr, length);
	free(buffr);
	va_end(arguements);
}

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
