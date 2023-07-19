#include "main.h"
#include <stdio.h>

int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	char ch, *str, c;
	int d;

	va_start(args, format);
	while ((ch = *format++) != '\0')
	{
		if (ch == '%')
		{
			ch = *format++;
			switch (ch)
				{
			case 'c':
				c = va_arg(args, int);
				putchar(c);
				printed_chars++;
				break;
			case 's':
				str = va_arg(args, char*);
				while (*str != '\0')
				{
					putchar(*str);
					printed_chars++;
					str++;
				}
				break;
			case 'd':
			case 'i':
				d = va_arg(args, int);
				printf("%d", d);
				printed_chars += snprintf(NULL, 0, "%d", d);
				break;
			case '%':
				putchar('%');
				printed_chars++;
				break;
			default:
				putchar('%');
				putchar(ch);
				printed_chars += 2;
				break;
			}
		}
		else
		{
			putchar(ch);
			printed_chars++;
		}
	}
	va_end(args);

	return printed_chars;
}

