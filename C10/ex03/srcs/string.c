#include "ft_tail.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

void	ft_putstr(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
}

char	*ft_strjoin(char *storage, char *readbuf)
{
	char	*result;
	int		len;
	int		readbuf_index;
	int		storage_index;

	len = ft_strlen(storage) + ft_strlen(readbuf);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
	    return (NULL);
	readbuf_index = 0;
	storage_index = 0;
	while(storage[storage_index])
	{
		result[storage_index] = storage[storage_index];
		storage_index++;
	}
	while(readbuf[readbuf_index])
	{
		result[storage_index] = readbuf[readbuf_index];
		storage_index++;
		readbuf_index++;
	}
	result[storage_index] = 0;
	return (result);
}

int	ft_atoi(char *str)
{
	int	m_cnt;
	int	result;

	m_cnt = 0;
	result = 0;
	while (*str <= 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			m_cnt++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	if (m_cnt % 2 == 1)
		result *= -1;
	return (result);
}
