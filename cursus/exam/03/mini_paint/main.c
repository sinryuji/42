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
	float	center_x;
	float	center_y;
	float	radius;
	char	c;

	int		x;
	int		y;
	char	*image;
	float	distance;

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
		read = fscanf(file, "%c %f %f %f %c\n", &r, &center_x, &center_y, &radius, &c);
		if (read != 5)
			break ;
		if (radius <= 0 || !(r == 'c' || r == 'C'))
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
				distance = sqrtf((x - center_x) * (x - center_x) + (y - center_y) * (y - center_y));
				if (distance <= radius)
				{
					if (r == 'c')
					{
						if (radius - distance < 1)
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
