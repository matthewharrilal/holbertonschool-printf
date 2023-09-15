#include "main.h"

#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

void formatSpecifier(va_list args, const char *format, int *counter)
{
	char c;
	char *nullStr;
	char *s;
	int64_t d;
	int64_t temp;
	unsigned int b;
	int i;
	int numDigits;
	int64_t currentDigit;
	int divisor;
	int index;
	bool firstSetBit;

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
		case 'i':
			d = va_arg(args, int);

			 if (d == 0)
			 {
				 putchar('0');
				 (*counter)++;
				 break;
			 }
			 else if (d < 0)
			 {
				 putchar('-');
				 (*counter)++;
				 d = -d;
			 }

			 /* Convert each digit to character and print */
			 numDigits = 0;
			 temp = llabs(d);
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
		case 'b':
			b = va_arg(args, int);

			if (b == 0)
			{
				putchar('0');
				break;
			}

			firstSetBit = false;

			for (index = CHAR_BIT * sizeof(unsigned int) - 1; index >= 0; index--)
			{
				if (b & (1UL << index))
				{
					firstSetBit = true;
					putchar('1'); /* We evaluate a 1 once the first bet is set given the truthyness test  */
				} else {
					putchar('0');
				}
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
