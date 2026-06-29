#include "ft_hexdump.h"

#define BUFFER_SIZE 32

const char *hex = "0123456789abcdef";

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

	result->contents = storage;
	result->length = ft_strlen(result->contents);

	free(storage);
	return (result);
}

void	print_hexnum(int i)
{
	int start;
	char	arr[8];
	int	n;

	start = i * 16;
	n = 8;
	while (n--)
	{
		arr[n] = hex[start % 16];
		start /= 16;
	}
	n = 0;
	while (n < 8)
	{
		write(1, &arr[n], 1);
		n++;
	}
	write(1, " ", 1);
}

void	print_hexdump(t_result *result)
{
	int	i;
	int	n;
	char *cont;

	i = 0;
	cont = result->contents + 16;
	while (i * 16 < result->length)
	{
		n = 0;
		print_hexnum(i);
		while (n < 15)
		{
			if (!cont[n])
			{
				break;
				i = -1;
			}
			write(1, &hex[cont[n] / 16], 1);
			write(1, &hex[cont[n] % 16], 1);
			write(1, &hex[cont[n + 1] / 16], 1);
			write(1, &hex[cont[n + 1] % 16], 1);
			write(1, " ", 1);
			n += 2;
		}
		write(1, "\n", 1);
		if (i == -1)
			break;
		i++;
		cont += 16;
	}	
}

void	print_c(t_result *result)
{
	print_hexdump(result);
}
