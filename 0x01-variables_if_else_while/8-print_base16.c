#include <stdio.h>
/**
 *main - Entry point
 *Description: 'print lowercase numbers of base 16'
 *Return: Always 0
 */
int main(void)
{
	int n;
	int s;

	for (n = 48; n <= 57; n++)
	{
		putchar(n);
	}
	for (s = 97; s <= 102; s++)
	{
		putchar(s);
	}
	putchar('\n');
	return (0);
}
