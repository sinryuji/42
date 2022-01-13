#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
// {abcdefghizklmnopqrstuvwxyz

void	print(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		if (c - 'n' >= 0)
			ft_putchar(c - 13);
		else
			ft_putchar(c + 13);
	}
	else if(c >= 'A' && c <= 'Z')
	{
		if (c - 'N' >= 0)
			ft_putchar(c - 13);
		else
			ft_putchar(c + 13);
	}
	else
		ft_putchar(c);
}

int main(int argc, char *argv[])
{
	int	i;

	i = -1;
	if (argc == 2)
	{
		while (argv[1][++i])
			print(argv[1][i]);
		
	}
	write(1, "\n", 1);
}

