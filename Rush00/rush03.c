void ft_putchar(char c);
void print(int i, int j, int x, int y);
void rush(int x, int y);

void print(int i, int j, int x, int y)
{
	if(i == 0 || i == y - 1)
	{
		if(j == 0)
			ft_putchar('A');
		else if(j == x - 1)
			ft_putchar('C');
		else
			ft_putchar('B');
	}
	else
	{
		if(j == 0 || j == x - 1)
			ft_putchar('B');
		else
			ft_putchar(' ');
	}
}

void rush(int x, int y)
{
	int i = 0;
	int j;

	while(i < y)
	{
		j = 0;
		while(j < x)
		{
			print(i, j, x, y);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
