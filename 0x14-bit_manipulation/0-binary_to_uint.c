#include "main.h"
/* #include <stdio.h> */

/**
 * binary_to_uint - Converts a binary number to an unsigned int
 *
 * @b: String containing binary number
 *
 * Return: the converted unsigned int number
 * or 0 on failure
 */
unsigned int binary_to_uint(const char *b)
{
	/* we will add up the binary digits from the string, b */
	/* into an unsigned int using bit manipulation */

	unsigned int converted_num = 0;
	int i;

	if (!b) /* NULL check for the string */
		return (0);

	for (i = 0; *b != '\0'; b++, i++)
	{
		/* printf("[%d]: %c\n", i, *b); */
		if (*b != '0' && *b != '1') /* return 0 if char is not 0 or 1 */
			return (0);

		/* bit shift left by 1 to make room for an extra digit */
		converted_num = converted_num << 1;

		if (*b == '1') /*if the current bit in the string is 1*/
		{ /*bitwise OR converted_num to make its least significant bit 1*/
			converted_num = converted_num | 1;
		}
	}
	return (converted_num);
}
