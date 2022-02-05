#include "ft_hexdump.h"

int main(int ac, char **av)
{
	t_result *result;
	int	fd;

	if (ac == 2 || ac == 3)
	{
		if (ac == 2)
			fd = open(av[1], O_RDONLY);
		else
			fd = open(av[2], O_RDONLY);

		if (fd == -1)
		{
			ft_putstr(strerror(errno));
			write(1, "\n", 1);
			return (0);
		}	
		result = read_file(fd);	
		if (ac == 2)
			print_hexdump(result);
		else
			print_c(result);
		free(result);
	}
	else if (ac == 1)
		write(1, "File name missing.\n", 19);
	else if (ac > 3)
		write(1, "Too many arguments.\n", 20);
}
