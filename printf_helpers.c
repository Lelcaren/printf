#include "main.h"
#include <unistd.h>

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @buffer: Array of chars
 * @buff_ind: Index at which to add the next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
    if (*buff_ind > 0)
        write(1, &buffer[0], *buff_ind);

    *buff_ind = 0;
}

/**
 * is_valid_specifier - Checks if a specifier is valid
 * @spec: Specifier character
 * Return: 1 if valid, 0 otherwise
 */
int is_valid_specifier(char spec)
{
    return (spec == 'c' || spec == 's' || spec == '%');
}

/**
 * print_specifier - Prints a specifier
 * @spec: Specifier character
 * @args: Arguments list
 * @buffer: Array to store printed characters
 * Return: Number of characters printed
 */
int print_specifier(char spec, va_list args, char buffer[])
{
    int printed = 0;

    switch (spec)
    {
    case 'c':
        printed = print_char(args, buffer);
        break;
    case 's':
        printed = print_string(args, buffer);
        break;
    case '%':
        printed = print_percent(args, buffer);
        break;
    }

    return printed;
}

