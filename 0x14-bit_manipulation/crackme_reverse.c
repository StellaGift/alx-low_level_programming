#include <stdint.h>
#include <stdio.h>


int main(void)
{
 	// uint8_t i;

	// char ecx;

	// uint32_t esi = 0x46c6f48;
	// char edx = 0xff;

	// for (i = 0; i < 4; i++)
	// {
	// 	esi = 0x46c6f48;
	// 	edx = 0xff;

	// 	edx = i;
	// 	ecx = i << 3;

	// 	esi = esi >> ecx;
	// 	ecx = esi;
	// 	edx = ecx & edx;

	// 	printf("%c ", edx);
	// }

	int	 key = 0x46c6f48;
	char a	 = 0xff;

	int index;
	int shifted_key;
	int masked_key;

	for (int i = 0; i < 4; i++)
	{
		index		 = i << 3;
		shifted_key = key >> index;
		masked_key	 = shifted_key & a;
		printf("%c", masked_key);
	}
	printf("\n");
	return (0);
}
