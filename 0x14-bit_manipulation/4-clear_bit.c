#include "main.h"

/**
 * clear_bit - To set value of the given bit to 0
 * @n: A pointer for the number to be changed,
 * @index: An index for bit to clear
 *
 * Return: 1 success, or -1 failure
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
