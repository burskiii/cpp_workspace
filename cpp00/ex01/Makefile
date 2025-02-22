# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygao <ygao@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/22 10:23:28 by ygao              #+#    #+#              #
#    Updated: 2025/02/22 17:04:29 by ygao             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CPP = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

SRC = phonebook.cpp main.cpp contacts.cpp contacts.hpp phonebook.hpp 

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
