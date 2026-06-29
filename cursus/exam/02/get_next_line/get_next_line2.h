#ifndef GET_NEXT_LINE2_H
# define GET_NEXT_LINE2_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char *get_next_line(int fd);

#endif
