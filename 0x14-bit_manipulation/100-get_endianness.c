#include "main.h"

/**
 * get_endianness - Function that checks the endianness
 * of a system
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	/* we create a short int which is 2 bytes long */
	short int num = 1;

	/* on a big endian system,    num is stored as 00000000 00000001 */
	/* on a little endian system, num is stored as 00000001 00000000 */

	/* we cast it into a 1 byte char*/
	char *num_ptr = (char *) &num;

	/* on a big endian system, the casted value takes */
	/* the MSB which will be 0 (00000000)*/
	/* on a little endian system, the casted value takes */
	/* the  LSB which will be (00000001)*/
	return (*num_ptr == 1);
}
