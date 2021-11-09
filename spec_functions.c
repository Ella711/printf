#include "main.h"

char *print_char(va_list arguements)
{
	char *str;
	char c;

	c = va_arg(arguements, int);

	if (c == 0)
		c = '\0';

	str = malloc(sizeof(char) * 2);
	if (str == NULL)
		return (NULL);
	
	str[0] = c;
	str[1] = '\0';

	return (str);
}

char *print_string(va_list arguements)
{
	char *str;
	char *copy;
	int len;

	str = va_arg(arguements, char *);
	if (str == NULL)
		str = "(null)";
	
	len = _strlen(str);

	copy = malloc(sizeof(char) * len + 1);
	if (copy == NULL)
		return (NULL);
	
	return (_strcpy(copy, str));
}
