#include "main.h"

/**
 * print_binary - Prints the binary representation of a number
 * using bit manipulation
 *
 * @n: Decimal number to convert
 *
 * Return: Prints out the binary number representation.
 */
void print_binary(unsigned long int n)
{
	unsigned long i;	 /* index for the loop that prints each bit */
	unsigned long msb; /* variable that stores value of current MSB */
	int encountered_non_zero_msb = 0; /* flag when 1st non-zero MSB is met */

	/* bit_filter's first bit (Most Significant Bit, MSB) will be set to 1 */
	unsigned long bit_filter = 1;

	/* bit_filter needs to be have the same num of bits as our input, n */
	unsigned long num_of_bits = sizeof(n) * 8; /*convert num of bytes to bits*/

	/* we shift bit_filter (num_of_bits - 1) places to the left so it has */
	/* the same num of bits as the input n while keeping its MSB as 1 */
	bit_filter = bit_filter << (num_of_bits - 1);

	if (n == 0) /* provision for when input number n = 0 */
	{
		_putchar('0');
		return;
	}

	/* we iterate num_of_bits times so we can print each bit */
	for (i = 0; i < num_of_bits; i++)
	{ /* bit_filter is ANDed with n to filter out the value of n's MSB */
		/* msb = 1, if the result of (bitfilter & n) is a non-zero number */
		msb = (bit_filter & n) > 1; /* msb = 0, otherwise */

		if (msb && !encountered_non_zero_msb)
		{ /*if the msb is 1 & we haven't encountered a non-zero msb yet */
			encountered_non_zero_msb = 1; /* flag = 1 to mark our encounter */
		}

		/* to avoid leading zeros, we only start printing bits from */
		/*  when we encounter our very 1st non-zero MSB*/
		if (encountered_non_zero_msb)
			_putchar(msb + '0');

		/* we bit shift n to the left by 1 to make its next bit the new MSB */
		n = n << 1;
	}
}
