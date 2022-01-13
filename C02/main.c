#include <stdio.h>
#include <string.h>

int main(void)
{
	char c1[] = "123";
	char c2[] = "456789";

	strlcpy(c1, c2, -1);
	printf("%s\n", c1);
	return 0;
}

