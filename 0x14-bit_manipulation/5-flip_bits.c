#include "main.h"

/**
 * flip_bits - To count the numbers of bits to be change
 * to gets frm one number to another
 * @n: First number
 * @m: Second number
 *
 * Return: The numbers of the bit to be changed
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, count = 0;
	unsigned long int current;
	unsigned long int exclusive = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		current = exclusive >> i;
		if (current & 1)
			count++;
	}

	return (count);
}
