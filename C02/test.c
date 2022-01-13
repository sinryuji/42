#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	printf("%d\n", c);
	printf("%c\n", c);
}

int main(void)
{
	char c = -97;
	unsigned char current = c;
	printf("%d\n", c);
	ft_putchar(current);
	return 0;
}

