#include <stdio.h>

int	ft_sqrt(int nb)
{
	unsigned int	i;

	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	i = 1;
	while (i * i <= nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}

int	main(void)
{
	printf("%d\n", ft_sqrt(2147483647));
}
