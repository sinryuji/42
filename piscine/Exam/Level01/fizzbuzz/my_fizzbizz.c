#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_number(int n)
{
	if (n < 10)
		ft_putchar(n + '0'); 
	else
	{
		ft_putchar(n / 10 + '0');
		ft_putchar(n % 10 + '0');
	}
}

int main(void)
{
	int	i;

	i = 1;
	while (i <= 100)
	{
		if (i % 3 == 0 && i % 5 == 0)
			write(1, "fizzbuzz", 8);
		else if(i % 3 == 0)
			write(1, "fizz", 4);
		else if(i % 5 == 0)
			write(1, "buzz", 4);
		else
			print_number(i);
		i++;
		ft_putchar('\n');
	}
}

