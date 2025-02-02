# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lekix <lekix@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 16:29:27 by kipouliq          #+#    #+#              #
#    Updated: 2025/02/02 19:07:56 by lekix            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = AMateria

CXX = c++

FLAGS = -std=c++98 -Wall -Wextra -Werror -g

SRCS = ./src/AMateria.cpp \
		./src/Ice.cpp \
		./src/Cure.cpp \
		./src/Character.cpp \
		./src/main.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(OBJS_PATH):
	mkdir -p $(OBJS_PATH)

$(OBJS_PATH)%.o: $(SCRS)%.cpp
	$(CXX) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) $(OBJS) -o $@

clean:
	rm -rf ./src/*.o

fclean:	clean
	rm -f $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re