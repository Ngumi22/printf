#include <stdarg.h>
#include <stdio.h>
#include "main.h"

int _printf(const char *format, ...) {
    va_list args;
    int count = 0;

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

int main() {
    _printf("This is a simple %s example. %c.\n", "printf", 'x');

    return 0;
}


