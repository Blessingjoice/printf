#ifndef MAIN_H
#define MAIN_H
#include  <stdio.h>
#include <limits.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

int _putchar(char c);
int pInt(va_list arg);
int print_Uint(va_list arg);
int _printf(const char *format, ...);
int pIdentifiers(char next, va_list arg);
int pChar(va_list arg);
int print_strng(va_list arg);
int print_percent(void);
void print_binary(unsigned int n, unsigned int *printed);
int print_UintToBinary(va_list arg);
int p_oct(va_list arg);
int print_UIntToHex(unsigned int num, char _case);
int printBase(va_list arg, char _case);
int pHexad(va_list arg);
int pHex(va_list arg);
int print_str(va_list arg);

/**
 * struct identifierStruct - structure definition of a printTypeStruct
 * @indentifier: type
 * @printer: function to print
 */
typedef struct identifierStruct
{
char *indentifier;
int (*printer)(va_list);
} identifierStruct;

#endif
