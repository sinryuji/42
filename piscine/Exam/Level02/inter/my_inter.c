#include <unistd.h>

int arr_check(char* arr, int arr_len, char c)
{
	while (arr_len-- > 0)
	{
		if (arr[arr_len] == c)
			return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		int	i;
		int j;
		int	len;

		len = 0;
		while (av[1][len])
			len++;
		char arr[len];
		j = 0;
		while (*av[1])
		{
			i = 0;
			while (av[2][i])
			{
				if (*av[1] == av[2][i] && arr_check(arr, len, *av[1]))
					arr[j++] = *av[1];
				i++;
			}
			av[1]++;
		}
		write(1, arr, j);
		write(1, "\n", 1);
	}
}
