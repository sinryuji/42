#include "ft_tail.h"

#define BUFFER_SIZE 32

t_result *read_file(int fd)
{
	t_result *result;
	int read_size;
	char read_buf[BUFFER_SIZE + 1];
	char *storage;
	read_size = 0;
	storage = malloc(sizeof(char));
	storage[0] = 0;
	while((read_size = read(fd, read_buf, BUFFER_SIZE)) > 0)
	{
		read_buf[read_size] = 0;
		storage = ft_strjoin(storage, read_buf);
	}
	close(fd);

	result = malloc(sizeof(t_result));

	result->og = storage;
	result->line = ft_split(result->og, "\n");

	free(storage);
	return (result);
}

void	print_tail(char **line)
{
	int	i;

	i = 0;
	while(line[i])
		i++;

	if (i <= 10)
		i = 0;
	else
		i -= 10;
	while(line[i])
	{
		ft_putstr(line[i]);
		write(1, "\n", 1);
		i++;
	}
}

void	print_c(char *og, char *nb)
{
	int	n;
	int	i;

	n = ft_atoi(nb);
	i = 0;

	while(og[i])
		i++;
	if (i - n <= 0)
		i = 0;
	else
		i -= n;
	while(og[i])
	{
		write(1, &og[i], 1);
		i++;
	}
}
