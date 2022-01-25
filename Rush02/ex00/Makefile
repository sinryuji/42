# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkong <jkong@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 01:16:55 by jkong             #+#    #+#              #
#    Updated: 2022/01/23 21:14:29 by jkong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = gcc
CFLAGS = -I$(INCLUDES_DIR) -Wall -Wextra -Werror
RM = rm -f
AR = ar
ARFLAGS = crs

TARGET = rush-02
SRCS_BASE = constructs.c destructs.c dictionary.c dictionary_init.c resolve.c ft_standard.c ft_string.c dict_util.c main.c
HEADER_BASE = rush.h
SRCS_DIR = ./srcs/
INCLUDES_DIR = ./includes/
INCS = $(addprefix $(INCLUDES_DIR), $(HEADER_BASE))
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_BASE))
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(TARGET)

re: fclean all

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

$(OBJS): $(INCS)

