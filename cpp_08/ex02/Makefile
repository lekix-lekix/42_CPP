# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lekix <lekix@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 16:29:27 by kipouliq          #+#    #+#              #
#    Updated: 2025/04/21 18:36:25 by lekix            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = span

CXX = c++

FLAGS = -std=c++98 -Wall -Wextra -Werror -g

SRCS = ./src/main.cpp \
		./src/Span.cpp

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

.PHONY: all clean fclean re