CC = gcc 
CFLAGS = -Wall -Werror -Wextra 
SRC_DIR = ./srcs/ 
INC_DIR = ./includes/
SRC_NAME = do_op.c  ft_put.c  main.c
SRCS = $(addprefix $(SRC_DIR), $(SRC_NAME))
OBJS = $(SRCS:.c=.o)
RM = rm -f
TARGET = do-op

%.o : %.c  
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR)

$(TARGET) : $(OBJS)  
	      $(CC) $(OBJS) -o $(TARGET)

all : $(TARGET)

clean :  
	$(RM) $(OBJS)

fclean : clean  
	$(RM) $(TARGET)

re : fclean all

.PHONY :  
	all clean fclean re
