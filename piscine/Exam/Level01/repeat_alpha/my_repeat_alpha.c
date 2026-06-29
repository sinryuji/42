#include <unistd.h>

void	print(char c)
{
	int	n;

	if (c >= 'a' && c <= 'z')
		n = c - ('a'- 1);
	else if (c >= 'A' && c <= 'Z')
		n = c - ('A'- 1);
	else
	{
		write(1, &c, 1);
		return ;
	}
	while (n)
	{
		write(1, &c, 1);
		n--;
	}
}

int main(int argc, char *argv[])
{
	int	i;
	
	i = -1;
	if (argc == 2)
	{
		while (argv[1][++i] != '\0')
			print(argv[1][i]);
	}
	write(1, "\n", 1);
}
