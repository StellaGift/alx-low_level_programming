#include "main.h"

/**
 * flip_bits - Returns the number of bits you would need
 * to flip to get from one number to another
 *
 * @n: First number of the comparison
 * @m: Second number of the comparison
 *
 * Return: 1 on success or -1 on failure
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long flippable_bits;
	unsigned int  count;

	/* perform xor on m & n to get a number whose bits are set to 1 for any */
	/* corresponding bits in m & n that are different & set to 0 otherwise */
	flippable_bits = m ^ n; /* bits of val 1 in this var rep flippable bits*/

	/* we iterate over flippable bits, shaving off */
	/* 1 bit on each pass till its value is 0*/
	for (count = 0; flippable_bits != 0; flippable_bits >>= 1)
	{
		/* flippable_bits is ANDed with 1 to determine val of rightmost bit.*/
		/* since the left bits will be 0, the rightmost bit determines our var*/
		/* val: 1 if the bit is 1 & 0 if the bit is 0. we then add up to count*/
		count = count + (flippable_bits & 1);
	}
	return (count);
}
