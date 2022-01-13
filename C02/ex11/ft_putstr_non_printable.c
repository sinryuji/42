#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

bool	is_char_printable(char c)
{
	printf("c : %d\n", c);
	return	(c >= 32 && c <= 126);
}

int ft_putstr_non_printable(char *str)
{
	int	i;
	unsigned char current;

	i = 0;
	while (true)
	{
		current = str[i];
		write(1, "\n", 1);
		printf("char : %d\n", str[i]);
		printf("current : %d\n", current);
		if (current == '\0')
			break;
		if (is_char_printable(current))
			ft_putchar(current);
		else
		{
			ft_putchar('\\');
			ft_putchar("0123456789abcdef"[current / 16]);
			ft_putchar("0123456789abcdef"[current % 16]);
		}
		i++;
	}
	return 0;
}

