#ifndef MAIN_H
#define MAIN_H
/* LIBRARIES */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/* typedef */

typedef struct mini
{
    char specifier;
    char* (*func)(va_list);
} format_spec;

/**
 * main.h -- Main header file for 0x11.C-printf
 * Authors: Ornella Russo - Marco Antonio Ordóñez
 */

/* secondary functions */
char *create_buffer(void);
void write_buffer(char *buffer, int length, va_list arguements);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
/* int _putchar(char c); */
int check_buffer_length(char *buffer, int length);

/* picks a functions based on format specifier */
char* (*get_spec_func(char c))(va_list);

/* printf functions */

int _printf(const char *format, ...);
char *print_char(va_list arguements);
/* char *print_int(va_list); can be used for char and decimal (%d %i)? */
/* int print_int(va_list arguements); */
/* char *print_special(va_list); %% */
char *print_string(va_list arguements);


#endif /* MAIN_H */

