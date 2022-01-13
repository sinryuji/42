#include <unistd.h>

void print_numbers(int n)
{
	char c;
 
	if(n < 10)
	{
		c = n + '0';
		write(1, "0", 1);
	       	write(1, &c, 1);
	}
	else
	{
		c = n / 10 + '0';
		write(1, &c, 1);
		c = n % 10 + '0';
		write(1, &c, 1);
	}	
}

void ft_print_comb2(void)
{
	int n = 0;
	int n2 = 1;

	while(n <= 98)
	{
		while(n2 <= 99)
		{
			print_numbers(n);
			write(1, " ", 1);
			print_numbers(n2);
			if(n < 98)
			{
				write(1, ", ", 2);
			}
			n2++;	
		}
		n++;
		n2 = n + 1;
	}
}

int main(void)
{
	ft_print_comb2();
}

