#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - Produces output according to a format
 * @format: A character string identifier to look for
 * @...: Varying number of arguments
 * Return: The number of characters printed
 * (excluding the null byte used to end output to strings)
 */

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%' && *(format + 1) != '\0')
        {
            format++;
            if (*format == '%')
            {
                // Consecutive '%' characters, consume one and print only one '%'
                putchar('%');
                count++;
            }
            else
            {
                switch (*format)
                {
                    case 'c':
                        putchar(va_arg(args, int));
                        count++;
                        break;
                    case 's':
                        count += printf("%s", va_arg(args, char *));
                        break;
                    case '%':
                        putchar('%');
                        count++;
                        break;
                    default:
                        putchar('%');
                        putchar(*format);
                        count += 2;
                        break;
                }
            }
        }
        else
        {
            putchar(*format);
            count++;
        }
        format++;
    }
    va_end(args);
    return count;
}
