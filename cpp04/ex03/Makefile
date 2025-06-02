NAME = recap

CXXFLAGS= -Wextra -Wall -Werror -std=c++98

SRCS = main.cpp AMateria.cpp ICharacter.cpp Character.cpp IMateriaSource.cpp MateriaSource.cpp Ice.cpp Cure.cpp 
OBJS = $(SRCS:.cpp=.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS) 

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re