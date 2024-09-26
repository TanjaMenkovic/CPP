NAME = easyfind

BUILD_FLAGS = -Wall -Wextra -std=c++11 -Werror

SRC =	main.cpp
H =		easyfind.hpp
OBJS = $(SRC:.cpp=.o)

.PHONY: all $(NAME) clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(H)
	c++ $(BUILD_FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(H)
	c++ $(BUILD_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all