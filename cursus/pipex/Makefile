# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 10:23:59 by hyeongki          #+#    #+#              #
#    Updated: 2022/10/02 21:18:09 by hyeongki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS_PATH = ./source/mandatory/
SRCS_NAME = main.c
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJS = $(SRCS:.c=.o)
BONUS_PATH = ./source/bonus/
BONUS_SRCS_NAME =
BONUS_SRCS = $(addprefix $(BONUS_PATH), $(BONUS_SRCS_NAME))
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
RM = rm -rf
AR = ar rcs
NAME = pipex
LIBFT_PATH = ./lib/libft/
LIBFT = ft
FT_PRINTF_PATH = ./lib/ft_printf/
FT_PRINTF = libftprintf.a

# Colors
GREEN = \x1b[32m
RED = \x1b[31m
RESET = \x1b[0m

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN).$(RESET)\c"

all : $(NAME)

$(NAME) :  $(OBJS)
	@make -C $(FT_PRINTF_PATH)
	@$(CC) $(CFLAGS) $^ $(FT_PRINTF_PATH)$(FT_PRINTF) -o $@
	@echo "$@: $(GREEN)$@ was created$(RESET)"

clean :
	@$(RM) $(OBJS) $(BONUS_OBJS) 
	@make -C $(FT_PRINTF_PATH) clean
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean : clean
	@$(RM) $(NAME)
	@make -C $(FT_PRINTF_PATH) fclean
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re : fclean all

.PHONY :
	all clean fclean re
