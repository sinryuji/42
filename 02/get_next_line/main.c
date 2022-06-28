#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	char	*ret;
	
	int fd = open("./test.txt", O_RDONLY);
	ret = get_next_line(fd);
	printf("%s", ret);
	ret = get_next_line(fd);
	printf("%s", ret);
}
