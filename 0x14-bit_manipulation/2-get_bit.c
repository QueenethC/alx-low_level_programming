#include "main.h"

/**
 * get_bit - To Returns the value of the bit at the index of a decimal number
 * @n: A number to search
 * @index: AN index of the bit,
 *
 * Return: The values of bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_val;

	if (index > 63)
		return (-1);

	bit_val = (n >> index) & 1;

	return (bit_val);
}
