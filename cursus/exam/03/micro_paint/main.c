#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	put_error(char *str)
{
	write(1, str, ft_strlen(str));
	return (1);
}

int	main(int argc, char **argv)
{
	FILE	*file;
	int		read;

	int		b_width;
	int		b_height;
	char	bc;

	char	r;
	float	tl_x;
	float	tl_y;
	float	width;
	float	height;
	char	c;

	int		x;
	int		y;
	char	*image;

	if (argc != 2)
		return (put_error("Error: argument\n"));
	file = fopen(argv[1], "r");
	if (!file)
		return (put_error("Error: Operation file corrupted\n"));
	read = fscanf(file, "%d %d %c\n", &b_width, &b_height, &bc);
	if (b_width < 1 || b_width > 300 || b_height < 1 || b_height > 300 || read != 3)
		return (put_error("Error: Operation file corrupted\n"));
	image = (char *)malloc(sizeof(char) * b_width * b_height);
	memset(image, bc, b_width * b_height);
	while (1)
	{
		read = fscanf(file, "%c %f %f %f %f %c\n", &r, &tl_x, &tl_y, &width, &height, &c);
		if (read != 6)
			break ;
		if (width == 0 || height == 0 || !(r == 'r' || r == 'R'))
		{
			free(image);
			fclose(file);
			return (put_error("Error: Operation file corrupted\n"));
		}
		x = 0;
		while (x < b_width)
		{
			y = 0;
			while (y < b_height)
			{
				if (x >= tl_x && x <= tl_x + width && y >= tl_y && y <= tl_y + height)
				{
					if (r == 'r')
					{
						if (x - tl_x < 1 ||  tl_x + width - x < 1 || y - tl_y < 1 || tl_y + height - y < 1)
							image[y * b_width + x] = c;
					}
					else
						image[y * b_width + x] = c;
				}
				y++;
			}
			x++;
		}

	}
	if (read != -1)
	{
		free(image);
		fclose(file);
		return (put_error("Error: Operation file corrupted\n"));
	}
	y = 0;
	while (y < b_height)
	{
		write(1, image + y * b_width, b_width);
		write(1, "\n", 1);
		y++;
	}
	free(image);
	fclose(file);
	return (0);
}
