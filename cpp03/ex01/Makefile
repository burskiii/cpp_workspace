NAME = ScavTrap

CPP = c++

CFLAGS = -Werror -Wextra -Wall -std=c++98

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp

RM = rm -rf

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
			$(CPP) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
			$(CPP) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

fclean : clean
			$(RM) $(NAME)

clean :
			$(RM) $(OBJS) $(NAME)

re : fclean all