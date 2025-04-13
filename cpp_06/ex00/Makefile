# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lekix <lekix@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 16:29:27 by kipouliq          #+#    #+#              #
#    Updated: 2025/04/13 18:00:31 by lekix            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = convert

CXX = c++

FLAGS = -std=c++98 -Wall -Wextra -Werror -g

SRCS = ./src/ScalarConverter.cpp \
		./src/utils.cpp \
		./src/main.cpp

OBJ = $(SRCS:.cpp=.o)

OBJS_DIR = .objs/

OBJS = $(addprefix $(OBJS_DIR), $(OBJ))

all: $(NAME)

$(OBJS_DIR)%.o: %.cpp
	mkdir -p $(@D)
	$(CXX) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS_DIR)

fclean:	clean
	rm -f $(NAME)

re: fclean
	make all

test			:	re
	echo
	valgrind ./convert
	echo
	valgrind ./convert 1 1
	echo
	valgrind ./convert 0
	echo
	valgrind ./convert a
	echo
	valgrind ./convert ""
	echo
	valgrind ./convert 10
	echo
	valgrind ./convert 127
	echo
	valgrind ./convert 128
	echo
	valgrind ./convert 00
	echo
	valgrind ./convert -1
	echo
	valgrind ./convert -128
	echo
	valgrind ./convert -129
	echo
	valgrind ./convert 42
	echo
	valgrind ./convert 2147483647
	echo
	valgrind ./convert 2147483648
	echo
	valgrind ./convert -2147483648
	echo
	valgrind ./convert -2147483649
	echo
	valgrind ./convert 42.0f
	echo
	valgrind ./convert .0f
	echo
	valgrind ./convert 0.f
	echo
	valgrind ./convert 0.0f
	echo
	valgrind ./convert 5.0f
	echo
	valgrind ./convert -2147483648.0f
	echo
	valgrind ./convert 2147483648.0f
	echo
	valgrind ./convert nanf
	echo
	valgrind ./convert +inff
	echo
	valgrind ./convert -inff
	echo
	valgrind ./convert 340282000000000000000000000000000000000.f
	echo
	valgrind ./convert 3402820000000000000000000000000000000000.f
	echo
	valgrind ./convert -340282000000000000000000000000000000000.f
	echo
	valgrind ./convert -3402820000000000000000000000000000000000.f
	echo
	valgrind ./convert -98.05ff
	echo
	valgrind ./convert nan
	echo
	valgrind ./convert +inf
	echo
	valgrind ./convert -inf
	echo
	valgrind ./convert -98.31aaa
	echo
	valgrind ./convert 99.31568
	echo
	valgrind ./convert .3156
	echo
	valgrind ./convert 98.
	echo
	valgrind ./convert ..
	echo
	valgrind ./convert .02.
	echo
	valgrind ./convert -3402820000000000000000000000000000000000.0
	echo
	valgrind ./convert 179769000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.
	echo
	valgrind ./convert 1797690000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.
	echo
	valgrind ./convert -179769000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0
	echo
	valgrind ./convert -1797690000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0
	echo
	valgrind ./convert hello

.PHONY: all clean fclean re