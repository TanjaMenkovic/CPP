NAME = animal

BUILD_FLAGS = -Wall -Wextra -std=c++98 -Werror

SRC =	Animal \
		Dog \
		Cat \
		WrongAnimal \
		WrongCat

H =		Animal \
		Dog \
		Cat \
		WrongAnimal \
		WrongCat

SRC_SUFF = $(addsuffix .cpp, $(SRC))
HEADER_SUFF = $(addsuffix .hpp, $(SRC))

SRCO = $(addsuffix .o, $(SRC))

.PHONY: all clean fclean re
all: $(NAME)

$(NAME): main.cpp $(SRC_SUFF) $(HEADER_SUFF)
	c++ $(BUILD_FLAGS) $(SRC_SUFF) main.cpp -o $(NAME)

clean:
	rm -f $(SRCSO)

fclean: clean
	rm -f $(NAME)

re: fclean all
