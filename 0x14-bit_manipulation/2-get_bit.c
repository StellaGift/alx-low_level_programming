#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index
 * using bit manipulation techniques
 *
 * @n: Decimal number to operate on
 * @index: The index of the bit of interest
 *
 * Return: the value (0 or 1) of the bit at given index
 * or -1 on failure
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long msb;		  /* variable that stores value of current MSB */
	unsigned int  curr_index; /* stores the current bit's index*/
	/* bit_filter's first bit (Most Significant Bit, MSB) will be set to 1 */
	unsigned long bit_filter = 1;
	/* bit_filter needs to be have the same num of bits as our input, n */
	unsigned long num_of_bits = sizeof(n) * 8; /*convert num of bytes to bits*/

	/* we shift bit_filter (num_of_bits - 1) places to the left so it has */
	/* the same num of bits as the input n while keeping its MSB as 1 */
	bit_filter = bit_filter << (num_of_bits - 1);

	/* we iterate num_of_bits times so we can get each bit */
	for (curr_index = (num_of_bits - 1); num_of_bits != 0; num_of_bits--)
	{ /* bit_filter is used bit-wisely to filter out n's MSB */
		msb = (bit_filter & n) > 1; /* msb is 1 if true or 0 if false */

		if (curr_index == index) /* curr_index is same as lookup index */
			return (msb); /* there's a match, so return bit at the index */

		/* bit shift n to the left by 1 to make its next bit the new MSB */
		n = n << 1;

		/* decrement to the next bit's index */
		curr_index--;
	}
	return (-1); /* index was out of bounds not matched/found */
}
