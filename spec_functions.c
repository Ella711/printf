#include "main.h"
/**
 * print_char - prints a char
 *@arguements: valist
 * Return: a char in a string
 */
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
/**
 * print_string - prints a string
 *@arguements: valist
 * Return: a string
 */
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
/**
 * integer_to_string - stores an integer into a string
 *@decimal_places: keeps the decimal places
 *@length: length of the integer
 *@num: number from va_list
 * Return: a string
 */
char *integer_to_string(int decimal_places, int length, int num)
{
	char *str;
	int i = 0;

	str = malloc(sizeof(char) * length + 2);
	if (str == NULL)
		return (NULL);

	if (num < 0) /* inputs negative sign */
	{
		str[0] = '-';
		i++;
	}
	while (num < 0) /* stores each decimal place in the string */
	{
		str[i] = ((num / decimal_places) * -1 + '0'); /* -1 for min int */
		num %= decimal_places;
		decimal_places /= 10;
		i++;
	}
	while (decimal_places >= 1) /* stores each decimal in
				      * string for positive nums
				      **/
	{
		str[i] = ((num / decimal_places) + '0'); /* stores the first decimal place */
		num %= decimal_places; /* mod of n */
		decimal_places /= 10; /* moves onto next decimal place */
		i++;
	}
	str[i] = '\0';
	return (str);
}

/**
 * print_integer - finds length of integer from arguements
 * @arguements: takes arg
 * Return: function to turn into string
 **/
char *print_integer(va_list arguements)
{
	int length, decimal_places, num, temp_num;

	num = va_arg(arguements, int);
	temp_num = num;
	length = 0;
	decimal_places = 1;

	if (num == 0) /* handles 0 being of length 1 */
	{
		length++;
		return (integer_to_string(decimal_places, length, num));
	}

	while (temp_num != 0) /* finds how many times it
				* can be divide by 10 to find
				* all the decimal places
				*/
	{
		length += 1;
		if (length > 1)
			decimal_places *= 10;
		temp_num /= 10;
	}

	return (integer_to_string(decimal_places, length, num));
}

