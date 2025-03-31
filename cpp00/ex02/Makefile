NAME = account

CPP = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

SRC = Account.cpp tests.cpp

OBJ = $(SRC:.cpp=.o)

%.o: %.cpp
		$(CPP) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CPP) $(CFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)s

fclean: clean
		$(RM) $(NAME)

clean:
		$(RM) $(OBJ) $(NAME)
	
re: fclean all
