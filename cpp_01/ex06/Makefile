# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 16:29:27 by kipouliq          #+#    #+#              #
#    Updated: 2025/01/21 16:36:17 by kipouliq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = harlFilter

CXX = c++

FLAGS = -std=c++98 -Wall -Wextra -Werror -g

SRCS = main.cpp \
		Harl.cpp

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
	rm -f $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re