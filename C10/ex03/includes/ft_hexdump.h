#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>
#include <stdlib.h>
#include <stdio.h>

/* struct */
typedef struct s_result t_result;

struct s_result
{
	char	*contents;
	int		length;
};

/* string.c */
int		ft_strlen(char *str);
int		ft_strcmp(char *str1, char *str2);
void	ft_putstr(char *str);
char	*ft_strjoin(char *storage, char *readbuf);
int		ft_atoi(char *str);

/* ft_hexdump.c */
t_result	*read_file(int fd);
void		print_hexnum(int i);
void		print_hexdump(t_result *result);
void		print_c(t_result *result);

#endif
