#include "main.h"

#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, char *);
	char *nextChar;
	char c;
	char *s;

	while (*format != '\0')
	{
		/* Look for percent operator know when we reach the arg list  */
		if (*format == '%')
		{
			nextChar = format++;

			if (*nextChar == 'c')
			{
				c = va_arg(args, int);
				putchar(c);	
			} else if (*nextChar == 's')
			{
				s = va_arg(args, char *);
				putchar(s);
			} else if (*nextChar == '%')
			{
				/* Print a regular percent sign  */
				putchar('%');
			}
			
		} else
		{
			/* If regular char then just putchar  */
			putchar(*format);
		}

		format++;
	}
}
