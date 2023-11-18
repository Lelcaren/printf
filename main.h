#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

#define BUFF_SIZE 1024

/* Other function declarations (if any) */

int _printf(const char *format, ...);
void print_buffer(char buffer[], int *buff_ind);
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list args);
int get_precision(const char *format, int *i, va_list args);
int get_size(const char *format, int *i);
int handle_print(const char *format, int *i, va_list args, char buffer[], int flags, int width, int precision, int size);

/* Declarations for printf_helpers.c */
int print_char(va_list args, char buffer[]);
int print_string(va_list args, char buffer[]);
int print_percent(va_list args, char buffer[]);

#endif /* MAIN_H */

