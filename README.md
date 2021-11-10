![](https://assets.website-files.com/6105315644a26f77912a1ada/610540e8b4cd6969794fe673_Holberton_School_logo-04-04.svg)

#   printf Project   #

**Building a customized Printf function**
This project is a mini printf function that we can find in the library <stdio.h>
if we are using the C Language. Basically it allows us to print any argument
given to standard or terminal output. This means that we can print any
combination of strings, integers and other different data types.


# Authorized functions and macros #

* write (man 2 write)
* malloc (man 3 malloc)
* free (man 3 free)
* va_start (man 3 va_start)
* va_end (man 3 va_end)
* va_copy (man 3 va_copy)
* va_arg (man 3 va_arg)


# Compile #

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c


# FLOWCHART #
<img src="https://github.com/Ella711/printf/blob/6cf64a6737d96184ef8b49fe3c454bd417996cd0/Flowchart%20_printf.png" />

### Note ###
If you want to review the manual of our _printf function you can execute
in your terminal:
~~~
$ man ./man_3_printf
~~~

## Formats ##
* %c: This type of format is used to represent a character
* %s: This type of format is used to represent a string of characters
* %d or %i: This type of format is used to represent base 10
  signed integer (int)

# Files of Project

* _printf: contains only the main function of our version of printf
* main.h: is our local library, it contains the public libraries, the different
  functions used in our project.
* aux_funcs.c: contiene las funciones auxiliares que se están utilizando para
  las secundarias de nuestro printf (strlen y strcpy)
* get_format_buffer.c: handles the storage buffer for what the functions are
  going to print at the end
* spec_functions.c: are all format-specific functions


## Environment ##
* Language: C
* OS: Ubuntu 20.04 LTS
* Compiler: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
* Style guidelines: [Betty style](https://github.com/holbertonschool/Betty/wiki)
and
[Betty-doc](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl)

### Authors ###
* [Ornella russo]
* [Marco Antonio Ordoñez]
