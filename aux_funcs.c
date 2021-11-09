#include "main.h"

/**
* _strlen - returns length of string
*@s: a string
*Return: i
*/

int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{

	}
	return (i);
}
/**
* _strcpy - prints n elements of array
*@dest: string
*@src: string
*Return: dest
*/

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = src[i];
	return (dest);
}