# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 17:01:39 by hyeongki          #+#    #+#              #
#    Updated: 2022/01/25 16:28:10 by hyeongki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC_DIR = ./srcs/
INC_DIR = ./includes/
SRC_NAME = ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c
SRCS = $(addprefix $(SRC_DIR), $(SRC_NAME))
OBJS = $(SRCS:.c=.o)
RM = rm -f
TARGET = libft.a

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR)

$(TARGET) : $(OBJS)
	ar rc $(TARGET) $(OBJS)

all : $(TARGET)

clean : 
	$(RM) $(OBJS)

fclean : clean 
	$(RM) $(TARGET)


re : fclean all

.PHONY : 
	all clean fclean re
