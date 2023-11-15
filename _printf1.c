#include "main.h"

/**
 * _printf - a function that produces output according to a format.
 * @format: a formatted input to the function.
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	if (format == NULL)
	{
		return (-1);
	}
	int count = 0;
	va_list args_list;

	va_start(args_list, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
		}
		else
		{
			format++;
			if (*format == '\0')
			{
				break;
			}
			else if (*format == '%')
			{
				write(1, format, 1);
				count++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(args_list, int);

				write(1, &c, 1);
				count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args_list, char *);

				if (str == NULL)
				{
					str = "(null)";
				}
				int str_len = 0;

				while (str[str_len] != '\0')
				{
					str_len++;
				}
				write(1, str, str_len);
				count += str_len;
			}
			else
			{
				write(1, format - 1, 2);
				count++;
			}
		}
		format++;
	}
	va_end(args_list);
	return (count);
}
