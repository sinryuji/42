#include "ft_cat.h"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int	fd;
		char buf[1];
		int	n;

		fd = open(av[1], O_RDONLY);
		n = 0;
		while(write(1, buf, read(fd, buf, 1)) > 0)
			n++;
		if (n < 1)
			write(1, "Cannot read file.\n", 18); 
	}
	else if (ac == 1)
		write(1, "File name missing.\n", 19);
	else if (ac > 2)
		write(1, "Too many arguments.\n", 20);
}
