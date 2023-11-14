#include "main.h"

/**
  * _putchar - writes the character c to stdout
  * @c: The character to print
  * Return: return 1 On success and -1 on encoutering error
  */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
