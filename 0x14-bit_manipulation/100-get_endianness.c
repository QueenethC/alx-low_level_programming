#include "main.h"

/**
 * get_endianness - To check if machine is a little or the big endian
 * Return: 0 as big, else 1 little
 */
int get_endianness(void)
{
	unsigned int i = 1;
	char *c = (char *) &i;

	return (*c);
}
