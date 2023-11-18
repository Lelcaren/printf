#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string with conversion specifiers
 *
 * Return: Number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%' && (*(format + 1) == 'c' || *(format + 1) == 's' ||
                                 *(format + 1) == '%' || *(format + 1) == 'd' ||
                                 *(format + 1) == 'i'))
        {
            format++;
            switch (*format)
            {
            case 'c':
                count += putchar(va_arg(args, int));
                break;
            case 's':
                count += _puts(va_arg(args, char *));
                break;
            case '%':
                count += putchar('%');
                break;
            case 'd':
            case 'i':
                count += _putn(va_arg(args, int));
                break;
            default:
                count += putchar('%');
                count += putchar(*format);
            }
        }
        else
        {
            count += putchar(*format);
        }
        format++;
    }

    va_end(args);
    return count;
}

/**
 * _putn - Custom function to print an integer
 * @n: Integer to be printed
 *
 * Return: Number of characters printed
 */
int _putn(int n)
{
    if (n < 0)
    {
        putchar('-');
        n = -n;
    }

    if (n / 10 != 0)
        _putn(n / 10);

    return putchar(n % 10 + '0');
}

