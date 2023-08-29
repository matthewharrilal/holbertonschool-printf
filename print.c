#include "main.h"

#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
        char c;
        char *s;
        int counter;

        va_list args;
        va_start(args, format);
        counter = 0;
        while (*format != '\0')
        {
                /* Look for percent operator know when we reach the arg list  */
                if (*format == '%')
                {

                        format++;
                        if (*format == 'c')
                        {
                                c = va_arg(args, int);
                                putchar(c);
                                counter++;
                        } else if (*format == 's')
                        {
                                /* Loop through entire string  */
                                while (*s != '\0')
                                {
                                        s = va_arg(args, char *);
                                        putchar(*s);
                                        s++;
                                        counter++;
                                }
                        } else if (*format == '%')
                        {
                                /* Print a regular percent sign  */
                                putchar('%');
                                counter++;
                        }

                } else
                {
                        /* If regular char then just putchar  */
                        putchar(*format);
                        counter++;
                }

                format++;
        }

        return counter;
}
