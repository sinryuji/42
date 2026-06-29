# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 22:37:19 by hyeongki          #+#    #+#              #
#    Updated: 2022/09/14 16:25:31 by hyeongki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS_PATH = ./source/
SRCS_NAME = ft_printf.c ft_printf_num.c ft_printf_num2.c ft_printf_prework.c ft_printf_string.c
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJS = $(SRCS:.c=.o)
RM = rm -rf
AR = ar rcs
NAME = libftprintf.a
LIBFT_PATH = ./lib/libft/
LIBFT = libft.a

# Colors
GREEN = \x1b[32m
RED = \x1b[31m
RESET = \x1b[0m

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(NAME) : $(OBJS)
	@$(MAKE) bonus -C $(LIBFT_PATH)
	@cp $(LIBFT_PATH)$(LIBFT) $(NAME)
	@$(AR) $@ $^
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

all : $(NAME)

clean : 
	@$(MAKE) clean -C $(LIBFT_PATH)
	@$(RM) $(OBJS)
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean : clean
	@$(RM) $(LIBFT_PATH)$(LIBFT)
	@$(RM) $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re : fclean all

.PHONY :
	all clean fclean re
