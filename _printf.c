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
        if (*format == '%' && (*(format + 1) == 'c' || *(format + 1) == 's' || *(format + 1) == '%'))
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
 * _puts - Custom function to print a string
 * @str: String to be printed
 *
 * Return: Number of characters printed
 */
int _puts(char *str)
{
    int count = 0;
    while (*str)
    {
        count += putchar(*str);
        str++;
    }
    return count;
}

/**
 * putchar - Custom function to write a character to stdout
 * @c: Character to be written
 *
 * Return: Number of characters printed
 */
int putchar(int c)
{
    return write(1, &c, 1);
}

