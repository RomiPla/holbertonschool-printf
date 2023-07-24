#include "main.h"
#include <stdio.h>

/**
 *_printf - Function printf
 *@format: is the armets of the function
 *Return: return 0 is correct return  -1 is error
*/
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0, d;
	char ch, *str, c;

	if (format)
	{
		if (args == NULL)
			return (-1);
		if (format[0] == '%' &&  format[1] == '\0')
			return (-1);
		if (format == NULL)
			return (-1);
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
						_putchar(c);
						printed_chars++;
						break;
					case 's':
						str = va_arg(args, char *);
						while (*str != '\0')
						{
							_putchar(*str);
							printed_chars++;
							str++;
						}
						break;
					case '%':
						_putchar('%');
						printed_chars++;
						break;
					case 'd':
					case 'i':
						d = va_arg(args, int);
						if (d < 0)
						{
							_putchar('-');
							printed_chars++;
							d = -d;
						}
						printed_chars += print_int(d);
						break;
					default:
						_putchar('%');
						_putchar(ch);
						printed_chars += 2;
						break;
				}
			}
			else
			{
				_putchar(ch);
				printed_chars++;
			}
		}
	}
	va_end(args);
	return (printed_chars);
}

/**
 *print_int - prints nums
 *@num: number to be printed
 *Return: chars printed
 */
int print_int(long int num)
{
	long int count = 0;
	long int reversed = 0;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (num != 0)
	{
		reversed = reversed * 10 + num % 10;
		num /= 10;
		count++;
	}
	while (reversed != 0)
	{
		_putchar('0' + reversed % 10);
		reversed /= 10;
	}
	return (count);
}
