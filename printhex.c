#include "main.h"
#include <unistd.h>
#include <math.h>
/**
 * printBase - base function for numbers
 * @arg: argument
 * @_case: (upper or lower)
 * Return: number of digits printed
 */

int printBase(va_list arg, char _case)
{
	unsigned int num = va_arg(arg, unsigned int);
	int digChars;

	if (num == 0)
		return (_putchar('0'));
	digChars = print_UIntToHex(num, _case);

	return (digChars);
}
/**
 * pHexad - prints a hexadecimal in lower case
 * @arg: list
 * Return: number of digits printed
 */

int pHexad(va_list arg)
{
	return (printBase(arg, 'a'));
}

/**
 * pHex - prints a hexadecimal in upper case
 * @arg: list
 * Return: number of digits printed
 */

int pHex(va_list arg)
{
	return (printBase(arg, 'A'));
}
