#include "main.h"

/**
 * set_bit - Sets the value of a bit to 1 at a given index
 * using bit manipulation techniques
 *
 * @n: Pointer to the decimal number to operate on
 * @index: The index of interest
 *
 * Return: 1 on success or -1 on failure
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long n_copy; /* stores a copy of val of n for bit manipulation */
	unsigned long msb;	  /* variable that stores value of current MSB */
	unsigned int  curr_index; /* stores the current bit's index*/

	/* bit_filter's first bit (Most Significant Bit, MSB) will be set to 1 */
	unsigned long bit_filter = 1;
	/* bit_filter needs to be have the same num of bits as our input, n */
	unsigned long num_of_bits = sizeof(*n) * 8; /*convert num of bytes to bits*/
	/* we shift bit_filter (num_of_bits - 1) places to the left so it has */
	/* the same num of bits as the input n while keeping its MSB as 1 */
	bit_filter = bit_filter << (num_of_bits - 1);

	if (index >= num_of_bits) /* index out of bounds */
		return (-1);

	if (!n) /*if n is a null pointer*/
		return (-1);

	n_copy = *n; /* copy original value of n over to n_copy */
	*n	   = 0;	 /* set val of n to 0 so we can bit manipulate it*/

	/* we iterate over each bit of n_copy */
	for (; num_of_bits != 0; num_of_bits--)
	{ /* bit_filter is used bit-wisely to filter out n's MSB */
		msb = (bit_filter & n_copy) > 1; /* msb is 1 if true or 0 if false */
		curr_index = (num_of_bits - 1);
		if (curr_index == index) /* curr_index is same as lookup index */
			msb = 1;			 /* there's a match, so set the bit to 1 */

		*n = *n | msb; /* add up digit into *n */
		if (num_of_bits > 1)
		{
			*n = *n << 1; /* bit shift *n left by 1 to make room for next bit */
			/* bit shift n_copy to the left by 1 to move to the next bit */
			n_copy = n_copy << 1;
		}
	}
	return (1); /* successfully set the bit */
}
