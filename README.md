# printf 

Is a custom function in C. It behaves similarly to the standard printf function, handling various format specifiers like %d, %s, and %c, but it is not a part of the standard C library.
The printf function prints a message to the screen using a "format string" that includes instructions for mixing multiple strings into the final string to be displayed on the screen.

# Synopsis
```c 
#include <stdio.h>
int _printf(const char *format, ...);

## Description

The _printf() function is used to produce formatted output according to the
format string specified by the 'format' argument. It writes the output to
the standard output stream (stdout).

The 'format' string may contain format specifiers that are replaced by the
values specified in subsequent arguments after the 'format' argument. Each
format specifier starts with a '%' character and is followed by one or more
conversion characters.

The return value of _printf() is the number of characters written to the
output stream upon success. If an error occurs, it returns a negative value,
indicating the error.

The _printf function processes the input format string and its optional arguments. It supports the following conversion specifiers:

%c: Prints a single character.
%s: Prints a string of characters.
%%: Prints a percent sign %.
%d and %i: Prints signed integers.
Any other character preceded by a percent sign will be treated as an escape sequence and printed accordingly.

## Usage

To use the _printf function in your C program, include the main.h header file, which contains the function prototype.
 You can then call the _printf function with a format string and any additional arguments.

```c
import printf

@@ -16,8 +47,10 @@ printf('geese')

# returns 'phenomenon'
printf('phenomenon')

## What we did

Writes the C string pointed by format to the standard output.

# Authors
This custom _printf function was developed by Agustina Araujo and Romina Pla.
