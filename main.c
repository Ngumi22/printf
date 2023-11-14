#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - selects correct function
 * @format:identifier to look for
 * Return:the length of string
 */
int _printf(const char *format, ...) {
    va_list args;
    int count = 0;
    void *addr;

    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%' && *(format + 1) != '\0') {
            format++; 
            switch (*format) {
                case 'c':
                    count += putchar(va_arg(args, int));
                    break;
                case 's':
                    count += printf("%s", va_arg(args, char *));
                    break;
                case 'd':
                case 'i':
                    count += printf("%d", va_arg(args, int));
                    break;
                case 'u':
                    count += printf("%u", va_arg(args, unsigned int));
                    break;
                case 'o':
                    count += printf("%o", va_arg(args, unsigned int));
                    break;
                case 'x':
                case 'X':
                    count += printf("%x", va_arg(args, unsigned int));
                    break;
                case 'p':
                    addr = va_arg(args, void *);
                    count += printf("%p", addr);
                    break;
                case '%':
                    count += putchar('%');
                    break;
                default:
                    count += putchar('%');
                    count += putchar(*format);
            }
        } else {
            count += putchar(*format);
        }
        format++;
    }

    va_end(args);

    return count;
}

