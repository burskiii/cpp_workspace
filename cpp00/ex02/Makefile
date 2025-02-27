# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygao <ygao@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/27 11:29:39 by ygao              #+#    #+#              #
#    Updated: 2025/02/27 17:42:05 by ygao             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account

CPP = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

SRC = Account.cpp Account.hpp test.cpp

OBJ = $(SRC:.cpp=.o)

%.o: %.cpp
		$(CPP) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CPP) $(CFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

fclean: clean
		$(RM) $(NAME)

clean:
		$(RM) $(OBJ) $(NAME)
	
re: fclean all
