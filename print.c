#include "main.h"

#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
        char c;
        char *s;
        int counter;
	char *nullStr;

        va_list args;
        va_start(args, format);

	if (format == NULL)
	{
		exit(98);
	}

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

                                s = va_arg(args, char *);

				if (s == NULL)
				{
					nullStr = "(null)";
					while (*nullStr != '\0')
					{
						putchar(*nullStr);
						nullStr++;
						counter++;
					}
				} else
				{
                                	/* Loop through entire string  */
                                	while (*s != '\0')
                                	{
                                        	putchar(*s);
                                        	s++;
                                        	counter++;
                                	}
				}
                        } else if (*format == '%')
                        {
                                /* Print a regular percent sign  */
                                putchar('%');
                                counter++;
                        } else
			{
				putchar(*format);
				exit(98);
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
