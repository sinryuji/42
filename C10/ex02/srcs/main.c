#include "ft_tail.h"

int main(int ac, char **av)
{
	t_result *result;
	int	fd;

	if (ac == 2 || ac == 4)
	{
		if (ac == 2)
			fd = open(av[1], O_RDONLY);
		else
			fd = open(av[3], O_RDONLY);

		if (fd == -1)
		{
			ft_putstr(strerror(errno));
			write(1, "\n", 1);
			return (0);
		}	
		result = read_file(fd);	

		if (ac == 2)
			print_tail(result->line);
		else
			print_c(result->og, av[2]);
		free(result->og);
		free(result->line);
		free(result);
	}
	else if (ac == 1 || ac == 3)
		write(1, "File name missing.\n", 19);
	else if (ac > 4)
		write(1, "Too many arguments.\n", 20);
}
