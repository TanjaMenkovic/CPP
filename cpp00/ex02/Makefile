NAME = account

BUILD_FLAGS = -Wall -Wextra -std=c++98 -Werror

SRC =	Account

SRC_SUFF = $(addsuffix .cpp, $(SRC))
HEADER_SUFF = $(addsuffix .hpp, $(SRC))

SRCSO = $(addsuffix .o, $(SRC))

.PHONY: all clean fclean re
all: $(NAME)

$(NAME): tests.cpp $(SRC_SUFF) $(HEADER_SUFF)
	c++ $(BUILD_FLAGS) $(SRC_SUFF) tests.cpp -o $(NAME)

clean:
	rm -f $(SRCSO)

fclean: clean
	rm -f $(NAME)

re: fclean all
