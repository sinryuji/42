CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC_DIR = srcs/
INC_DIR = includes/
SRC_NAME = main.c
SRCS = $(addprefix $(SRC_DIR), $(SRC_NAME))
OBJS = $(SRCS:.c=.o)
TARGET = ft_cat

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR)

$(TARGET) : $(OBJS)
			  $(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

all : $(TARGET)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(TRAGET)

.PHONY :
	all clean fcleanl
