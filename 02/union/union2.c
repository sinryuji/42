#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		int	used[255];
		int	i;
		int	j;

		i = 0;
		while (i < 255)
			used[i++] = 0;
		i = 1;
		while (i < 3)
		{
			j = 0;
			while (argv[i][j])
			{
				if (!used[argv[i][j]])
				{
					write(1, &argv[i][j], 1);
					used[argv[i][j]] = 1;
				}
				j++;	
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
