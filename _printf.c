#include "main.h"

/**
 * _printf - miniprint function
 * @format: what's to be printed
 * Return: length of what was printed
 */
int _printf(const char *format, ...)
{
	int length = 0, tot_length = 0, i = 0, j = 0;
	char *buffer, *str;
	char* (*func)(va_list);
	va_list arguments;

	if (format == NULL)
		return (-1);

	buffer = create_buffer();
	if (buffer == NULL)
		return (-1);
	va_start(arguments, format);

	while (format[i] != '\0')
	{
		if (format[i] != '%') /* copy format into buffer till % */
		{
			buffer[length++] = format[i++];
			tot_length++;
		}
		else /* if format[i] = % */
		{
			i++;
			if (format[i] == '\0') /* nothing after the % */
			{
				va_end(arguments);
				free(buffer);
				return (-1);
			}
			if (format[i] == '%') /* handles %% */
			{
				buffer[length++] = format[i];
				tot_length++;
			}
			else
			{
				func = get_spec_func(format[i]); /* looks up required function */
				if (func == NULL) /* if it doesn't find a spec, print % */
				{
					buffer[length++] = '%';
					tot_length++;
					buffer[length++] = format[i];
					tot_length++;
				}
				else /* func will return str and copy to buffer */
				{
					str = func(arguments);
					if (str == NULL)
					{
						va_end(arguments);
						free(buffer);
						return (-1);
					}
					if (format[i] == 'c' && str[0] == '\0')
					{
						buffer[length++] = '\0';
						tot_length++;
					}
					j = 0;
					while (str[j] != '\0')
					{
						buffer[length++] = str[j];
						tot_length++;
						j++;
					}
					free(str);
				}
			}
			i++;
		}
	}
	write_buffer(buffer, length, arguments);
	return (tot_length);
}

