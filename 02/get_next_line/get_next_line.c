#include "get_next_line.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*ft_strchr(char *str, int c)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
//	if (*str == '\0')
//		return (str);
//	if (*str == c)
//		return (str);
	return (0);
}

static char	*ft_strjoin(char *str1, char *str2)
{
	char	*ret;
	int		i;

	ret = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (*str1)
		ret[i++] = *str1++;
	while (*str2)
		ret[i++] = *str2++;
	ret[i] = '\0';
	return (ret);
}

static char	*ft_strndup(char *str, int n)
{
	char	*ret;
	int		i;

	if(!str)
		return (NULL);
	ret = malloc(sizeof(char) * (n + 1));
	if(!ret)
		return (NULL);
	i = 0;
	while (str[i] && i < n)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buf;
	ssize_t		bytes;
	char		*tmp;
	char		*ret;
	int			i;

	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (NULL);
	bytes = 1;
	while (!(ft_strchr(save, '\n')) && bytes != 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[bytes] = '\0';
		if (!save)
			tmp = ft_strndup(buf, ft_strlen(buf));
		else
			tmp = ft_strjoin(save, buf);
		free(save);
		save = tmp;
	}
	free(buf);
	if (!save)
		return (NULL);
	if (!*save)
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	ret = ft_strndup(save, i + 1);
	if (ft_strlen(save) == i)
		tmp = NULL;
	else
		tmp = ft_strndup(save + i + 1, ft_strlen(save));
	free(save);
	save = tmp;
	return (ret);
}
