#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
/**
 * print_UintToBinary - prints an integer and a binary.
 * @arg: argument
 * Return: 0
 */
int print_UintToBinary(va_list arg)
{

	unsigned int n = va_arg(arg, unsigned int);
	unsigned int printed;

	print_binary(n, &printed);

	return (printed);
}


/**
 * p_oct - prints number in octal base.
 * @arg: argument
 * Return: number of octals printed
 */

int p_oct(va_list arg)
{
	unsigned int num = va_arg(arg, unsigned int);
	unsigned int new;
	char *octa;
	int i, m, printed_char = 0;

	if (num == 0)
		return (_putchar('0'));
	for (new = num; new != 0; m++)
	{
		new = new / 8;
	}
	octa = malloc(m);
	if (!octa)
		return (-1);

	for (i = m - 1; i >= 0; i--)
	{
		octa[i] = num % 8 + '0';
		num = num / 8;
	}

	for (i = 0; i < m && octa[i] == '0'; i++)
	;
	for (; i < m; i++)
	{
		_putchar(octa[i]);
		printed_char++;
	}
	free(octa);
	return (printed_char);
}

/**
 * print_UIntToHex - prints unsigned integer to hexadecimal.
 * @num: number to print
 * @_case: (upper or lower)
 * Return: number of characters printed
 */
int print_UIntToHex(unsigned int num, char _case)
{
	unsigned int dig;
	int i, m, rem, digChars = 0;
	char *numhex;

	for (dig = num; dig != 0; digChars++, dig /= 16)
	;

	numhex = malloc(digChars);
	for (i = 0; num != 0; i++)
	{
		rem = num % 16;
		if (rem < 10)
			numhex[i] = rem + '0';
		else
			numhex[i] = rem - 10 + _case;
		num = num / 16;
	}
	for (m = i - 1; m >= 0; m--)
		_putchar(numhex[m]);
	free(numhex);
	return (digChars);
}
