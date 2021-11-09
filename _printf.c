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
    va_list arguements;

    if (format == NULL)
        return (-1);
    
    buffer = create_buffer();
    if (buffer == NULL)
        return (-1);
    va_start(arguements, format);

    while(format[i] != '\0')
    {
        if(format[i] != '%') /* copy format into buffer till % */
        {
            length = check_buffer_length(buffer, length);
            buffer[length++] = format[i++];
            tot_length++;
        }
        else /* if format[i] = % */ 
        {
            i++;
            if (format[i] == '\0') /* nothing after the % */
            {
                va_end(arguements);
                free(buffer);
                return(-1);
            }
            if (format[i] == '%') /* handles %% */
            {
                length = check_buffer_length(buffer, length);
                buffer[length++] = format[i];
                tot_length++;
            }
            else
            {
                func = get_spec_func(format[i]); /* looks up required function */
                if (func == NULL) /* if it doesn't find a spec, print % */
                {
                    length = check_buffer_length(buffer, length);
                    buffer[length++] = '%';
                    tot_length++;
                    buffer[length++] = format[i];
                    tot_length++;
                }
                else /* func will return str and copy to buffer */
                {
                    str = func(arguements);
                    if (str == NULL)
                    {
                        va_end(arguements);
                        free(buffer);
                        return (-1);
                    }
                    if (format[i] == 'c' && str[0] == '\0')
                    {
                        length = check_buffer_length(buffer, length);
                        buffer[length++] = '\0';
                        tot_length++;
                    }
                    j = 0;
                    while (str[j] != '\0')
                    {
                        length = check_buffer_length(buffer, length);
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
    write_buffer(buffer, length, arguements);
    return (tot_length);
}