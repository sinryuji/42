# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 19:02:18 by hyeongki          #+#    #+#              #
#    Updated: 2023/01/02 15:45:23 by hyeongki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------------[ COLOR ]-----------------
COMPILE_COLOR	=	"\033[1;34m"
BUILD_COLOR		=	"\033[1;32m"
MODE_COLOR		=	"\033[1;35m"
DEL_COLOR		=	"\033[1;31m"
END				=	"\033[0;0m"
CLEAR			=	"\x1b[1A\x1b[M"
#---------------[ FILE ]-----------------
NAME			=	scavtrap
SRC				=	main.cpp\
					ClapTrap.cpp\
					ScavTrap.cpp
OBJ				=	$(SRC:.cpp=.o)
#----------------[ CMD ]------------------
CC				=	c++
CXXFLAGS		=	-Wall -Wextra -Werror -std=c++98
RM				=	rm -rf

all: $(NAME)

%.o : %.cpp
	@echo $(COMPILE_COLOR) "💾 [$<] Compiling..." $(END)
	@$(CC) $(CXXFLAGS) -c $< -o $@
	@echo $(COMPILE_COLOR) "✨ [$@] was created" $(END)

$(NAME): $(OBJ)
	@echo $(BUILD_COLOR) "🔨 [$@] Building..." $(END)
	@$(CC) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo $(BUILD_COLOR) "🎉 [$@] was created" $(END)

clean:
	@$(RM) $(OBJ)
	@echo $(DEL_COLOR) "🧹 [Object files] were removed" $(END)

fclean: clean
	@$(RM) $(NAME)
	@echo $(DEL_COLOR) "🧹 [$(NAME)] were removed" $(END)

re:
	@make fclean
	@make all

.PHONY: all clean fclean re
