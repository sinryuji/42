void ft_putchar(char c);
void print(int boolean, char c1, char c2);
void rush(int x, int y);

void print(int boolean, char c1, char c2)
{
	if(boolean == 1)
		ft_putchar(c1);
	else
		ft_putchar(c2);
}

void rush(int x, int y)
{
	int i = 0;
	int j;
	int boolean;

	while(i < y)
	{
		j = 0;
		while (j < x)
		{
			boolean = j == 0 || j == x - 1 ? 1 : 0;
			if(i == 0 || i == y - 1)
				print(boolean, 'o', '-');
			else
				print(boolean, '|', ' ');
			j++;
		}	
		i++;
		ft_putchar('\n');
	}
}
