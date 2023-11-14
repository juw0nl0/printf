#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_char - Helper function to print a character
 * @c: Character to print
 * @count: Pointer to the count of characters printed
 */
static void print_char(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}


/**
 * print_str - Helper function to print a string
 * @str: String to print
 * @count: Pointer to the count of characters printed
 */
static void print_str(char *str, int *count)
{
	while (*str)
	{
		write(1, str++, 1);
		(*count)++;
	}
}

/**
 * _printf - Custom printf function
 * @format: Format string
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	if (!format)
		return (-1);

	va_list args_list;
	int count = 0;

	va_start(args_list, format);
	while (*format)
	{
		if (*format != '%')
		{
			print_char(*format, &count);
		}
		else
		{
			format++;
			if (*format == '%' || *format == '\0')
			{
				print_char('%', &count);
			}
			else if (*format == 'c')
			{
				char c = va_arg(args_list, int);

				print_char(c, &count);
			}
			else if (*format == 's')
			{
				char *str = va_arg(args_list, char*);

				print_str(str, &count);
			}
		}
		format++;
	}
	va_end(args_list);
	return (count);
}
