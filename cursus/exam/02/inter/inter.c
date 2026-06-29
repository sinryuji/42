#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int	used[255];
		int	i;
		int	j;

		i = 0;
		while (i < 255)
			used[i++] = 0;
		i = 0;
		while (argv[1][i])
		{
			j = 0;
			while (argv[2][j])
			{
				if (argv[1][i] == argv[2][j] && !used[(unsigned char)argv[1][i]])
				{
					used[(unsigned char)argv[1][i]] = 1;
					write(1, &argv[1][i], 1);
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
