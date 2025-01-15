# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lekix <lekix@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 16:29:27 by kipouliq          #+#    #+#              #
#    Updated: 2025/01/15 16:45:48 by lekix            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = hi_this_is_brain

CXX = c++

FLAGS = -std=c++98 -Wall -Wextra -Werror -g

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(OBJS_PATH):
	mkdir -p $(OBJS_PATH)

$(OBJS_PATH)%.o: $(SCRS)%.cpp
	$(CXX) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) $(OBJS) -o $@

clean:
	rm -rf ./*.o

fclean:	clean
	rm $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re