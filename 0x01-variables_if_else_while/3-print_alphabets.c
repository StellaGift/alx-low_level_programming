#include <stdio.h>
/**
  *main - Entry point
  *Description: 'prints alphabets in lower and upper case'
  *Return: always 0
  */
int main(void)
{
	int n = 97;
	int s = 65;

	while (n <= 122)
	{
		putchar(n);
		n++;
	}
	while (s <= 90)
	{
		putchar(s);
		s++;
	}
		putchar('\n');
		return (0);
}
