#include <unistd.h>
#include <stdio.h>

#define HEX_SIZE 16

const char *hex = "0123456789abcdef";

int print_hex_cont(void *addr)
{
    char *addr_char;
    int	n;

    addr_char = (char *)addr;
    n = 0;
    while(n < HEX_SIZE - 1)
    {
	if (!addr_char[n])
	{
	    n = -1;
	    break;
	}
	write(1, &hex[addr_char[n] / HEX_SIZE], 1);
	write(1, &hex[addr_char[n] % HEX_SIZE], 1);
	write(1, &hex[addr_char[n + 1] / HEX_SIZE], 1);
	write(1, &hex[addr_char[n + 1] % HEX_SIZE], 1);
	write(1, " ", 1);
	n += 2;
    }
    if (n == -1)
	write(1, "    ", 4);
    n = 0;
    while(n < HEX_SIZE)
    {
	if (!addr_char[n])
	    return (1);
	if (addr_char[n] <= 31 || addr_char[n] == 127)
	    write(1, ".", 1);
	else
	    write(1, &addr_char[n], 1);
	n++;
    }
    return (0);
}   

void	print_addr(void	*addr)
{
    long long	addr_val;
    int	i;
    char addr_hex[HEX_SIZE];

    addr_val = (long long)addr;
    i = HEX_SIZE;
    while (i--)
    {
	addr_hex[i] = hex[addr_val % HEX_SIZE];
	addr_val /= HEX_SIZE;
    }
    while (i < HEX_SIZE)
    {
	write(1, &addr_hex[i], 1);
	i++;
    }
    write(1, ": ", 2);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
    unsigned int i;
    int result;

    i = 0;
    if (!size)
	return (addr);    
    while (i * HEX_SIZE < size)
    {
	print_addr(addr + (i * HEX_SIZE));
	result = print_hex_cont(addr + (i * HEX_SIZE));
	write(1, "\n", 1);
	if (result)
	    break;
	i++;
    }

    return (addr);
}

int main()
{
    ft_print_memory("Bonjour les aminches.\t\n\tc est fou\ttout\tce au on peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n \0", 255);
}
