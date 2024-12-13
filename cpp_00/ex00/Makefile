# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 16:29:27 by kipouliq          #+#    #+#              #
#    Updated: 2024/12/13 17:38:08 by kipouliq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CXX = c++

FLAGS = -std=c++98 -Wall -Wextra -Werror -g

SRCS = megaphone.cpp

OBJS = $(SRCS:.cpp=.o)

OBJS_PATH = ./.build/

-include $(DEPS)

all: $(OBJS_PATH) $(NAME)

$(OBJS_PATH):
	mkdir -p $(OBJS_PATH)

$(OBJS_PATH)%.o: $(SCRS)%.cpp
	$(CXX) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) $(OBJS) -o $@

clean:
	rm -rf $(OBJS_PATH)

fclean:
	rm -rf $(NAME) $(OBJS_PATH)

re: fclean
	make all

.PHONY: all clean fclean re