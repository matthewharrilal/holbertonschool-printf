#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "print.c"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
	int len, len2;

	len = _printf("%u\n", -1024);
	printf("Difference\n");
	len2 = printf("%u\n", -1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}
