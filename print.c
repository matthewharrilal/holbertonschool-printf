#include "main.h"

#include <stdio.h>
#include <stdarg.h>


void formatSpecifier(va_list args, const char *format, int *counter)
{
	char c;
	char *nullStr;
	char *s;
	int d;
	int temp;
	int i;
	int numDigits;
	int currentDigit;
	int divisor;

	switch (*format)
	{
		case 'c':
		    	c = va_arg(args, int);
    			putchar(c);	
    			(*counter)++;
			break;
		case 's':
			s = va_arg(args, char *);
			if (s == NULL)
			{
				nullStr = "(null)";
				while (*nullStr != '\0')
				{
					putchar(*nullStr);
					nullStr++;
					(*counter)++;
				}
			} else
			{
				/* Loop through entire string */
				while (*s != '\0')
				{
					putchar(*s);
					s++;
					(*counter)++;
				}
			}
			break;
		case '%':
			putchar('%');
			(*counter)++;
			break;
		case 'd':
			d = va_arg(args, int);

			 if (d == 0)
			 {
				 putchar('0');
				 (*counter)++;
			 }
			 else if (d < 0)
			 {
				 putchar('-');
				 (*counter)++;
				 d = -d;
			 }

			 /* Convert each digit to character and print */
			 numDigits = 0;
			 temp = d;
			 while (temp > 0)
			 {
				 temp /= 10;
				 numDigits++;
			 }

			 divisor = 1;
			 for (i = 1; i < numDigits; i++)
			 {
				 divisor *= 10;
			 }

			 while (divisor > 0)
			 {
				 currentDigit = d / divisor;
				 putchar('0' + currentDigit); /* Convert to character before printing */
				 (*counter)++;
				 d %= divisor;
				 divisor /= 10;
			 }
 			break;
		default:
			 if (*format == '\0')
			{
				exit(98);
			}

			putchar('%'); /* Print % for unsupported format specifier */
			(*counter)++;
			while (*format != '\0' && *format != ' ')
			{
				putchar(*format);
				format++;
				(*counter)++;
			}

			break;			
	}
}

int _printf(const char *format, ...)
{
        int counter;
	
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
			formatSpecifier(args, format, &counter);

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
