#ifndef MAIN_H
#define MAIN_H
/* LIBRARIES */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * main.h -- Main header file for 0x11.C-printf
 * Authors: Ornella Russo - Marco Antonio Ordóñez
 */

/* secondary functions */

/* picks a functions based on format specifier */
void* (*get_spec_func(char c))(va_list);

/* printf functions */

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list);
/* char *print_int(va_list); can be used for char and decimal (%d %i)? */
int print_int(va_list);
/* char *print_special(va_list); %% */
int print_string(va_list);


#endif /* MAIN_H */

