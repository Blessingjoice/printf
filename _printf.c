#include <stddef.h>
#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * pIdentifiers - prints special characters
 * @next: character after the %
 * @arg: argument for the identifier
 * Return: the number of characters printed.
 */
int pIdentifiers(char next, va_list arg)
{
	int func;
	identifierStruct funct[] = {
		{"c", pChar},
		{"s", print_strng},
		{"d", pInt},
		{"i", pInt},
		{"u", print_Uint},
		{"b", print_UintToBinary},
		{"o", p_oct},
		{"x", pHexad},
		{"X", pHex},
		{"S", print_str},
		{NULL, NULL}
	};

	for (func = 0; funct[func].indentifier != NULL; func++)
	{
		if (funct[func].indentifier[0] == next)
			return (funct[func].printer(arg));
	}
	return (0);
}
/**
 * _printf - copy printf from stdio
 * Desc: produces output according to a format
 *
 * @format: character string composed of zero or more directives
 * Return: the number of characters printed.
 * return -1 for incomplete identifier error.
 */

int _printf(const char *format, ...)
{
	unsigned int i;
	int print_ident = 0, printed_char = 0;
	va_list arg;

	va_start(arg, format);
	if (format == NULL)
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			printed_char++;
			continue;
		}
		if (format[i + 1] == '%')
		{
			_putchar('%');
			printed_char++;
			i++;
			continue;
		}
		if (format[i + 1] == '\0')
			return (-1);

		print_ident = pIdentifiers(format[i + 1], arg);
		if (print_ident == -1 || print_ident != 0)
			i++;
		if (print_ident > 0)
			printed_char += print_ident;

		if (print_ident == 0)
		{
			_putchar('%');
			printed_char++;
		}
	}
	va_end(arg);
	return (printed_char);
}
