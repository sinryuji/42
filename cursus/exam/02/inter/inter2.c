#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		int used[255];
		int	i;

		i = 0;
		while (i < 255)
			used[i++] = 0;
		i = 0;
		while (argv[2][i])
			used[argv[2][i++]] = 1;
		i = 0;
		while (argv[1][i])
		{
			if (used[argv[1][i]] == 1)
			{
				write(1, &argv[1][i], 1);
				used[argv[1][i]]++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
