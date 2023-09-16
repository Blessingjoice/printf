#include "main.h"
#include <unistd.h>
#include <stdio.h>
/**
 * pChar - writes the character c to stdout
 * @arg: argument
 * Return: On success 1 and On error, -1 is returned
 */
int pChar(va_list arg)
{
	return (_putchar(va_arg(arg, int)));
}

/**
 * pInt - prints an integer.
 * @arg: argument
 * Return: 0
 */

int pInt(va_list arg)
{

	unsigned int divisor = 1, i, resp, printed_char = 0;
	int n = va_arg(arg, int);

	if (n < 0)
	{
		_putchar('-');
		printed_char++;
		n *= -1;
	}

	for (i = 0; n / divisor > 9; i++, divisor *= 10)
	;

	for (; divisor >= 1; n %= divisor, divisor /= 10, printed_char++)
	{
		resp = n / divisor;
		_putchar('0' + resp);
	}
	return (printed_char);
}


/**
 * print_str - prints a string with an upper case specificer
 * @arg: argument
 * Return: number of character printed
 */

int print_str(va_list arg)
{
	int i;
	char *strng = va_arg(arg, char*);

	if (strng == NULL)
	strng = "(null)";
	else if (*strng == '\0')
	return (-1);

	for (i = 0; strng[i]; i++)
	{
		if ((strng[i] < 32 && strng[i] > 0) || strng[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			if (i < 16)
				_putchar('0');

			print_UIntToHex(strng[i], 'A');
		}
		else
			_putchar(strng[i]);
	}
	return (i);
}

/**
 * print_strng - prints a string with a lower case specifier
 * @arg: argument
 * Return: number of character printed
 */

int print_strng(va_list arg)
{
	int i;
	char *strng = va_arg(arg, char*);

	if (strng == NULL)
		strng = "(null)";
	else if (*strng == '\0')
		return (-1);

	for (i = 0; strng[i]; i++)
		_putchar(strng[i]);
	return (i);
}

/**
 * print_Uint - prints an unsigned integer.
 * @arg: argument
 * Return: 0
 */

int print_Uint(va_list arg)
{
	int divisor = 1, i, resp;
	unsigned int n = va_arg(arg, unsigned int);

	for (i = 0; n / divisor > 9; i++, divisor *= 10)
	;

	for (;divisor >= 1; n %= divisor, divisor /= 10)
	{
		resp = n / divisor;
		_putchar('0' + resp);
	}
	return (i + 1);
}
