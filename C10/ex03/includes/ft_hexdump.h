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
	char **line;
	char *og;
};

/* string.c */
int		ft_strlen(char *str);
int		ft_strcmp(char *str1, char *str2);
void	ft_putstr(char *str);
char	*ft_strjoin(char *storage, char *readbuf);
int		ft_atoi(char *str);

/* ft_split.c */
char	*ft_strdup(char *src, int n);
int		sep_check(char c, char *charset);
int		get_word_cnt(char *str, char *charset);
char	**ft_split(char *str, char *charset);

/* ft_tail.c */
t_result	*read_file(int fd);
void		print_tail(char **line);
void		print_c(char *og, char *nb);

#endif
