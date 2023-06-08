#include "main.h"

/**
 * set_bit - To set bit at the given index to 1
 * @n: A pointer for the number to be changed,
 * @index: index of the bit to set to 1
 *
 * Return: 1 success, else -1 failure
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}
