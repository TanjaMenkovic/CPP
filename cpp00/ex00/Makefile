NAME = megaphone

BUILD_FLAGS = -Wall -Wextra -std=c++98 -Werror

SRC = megaphone

SRC_SUFF = $(addsuffix .cpp, $(SRC))
SRCSO = $(addsuffix .o, $(SRC))

.PHONY: all clean fclean re
all: $(NAME)

$(NAME): $(SRC_SUFF)
	c++ $(BUILD_FLAGS) $(SRC_SUFF) -o $(NAME)

clean:
	rm -f $(SRCSO)

fclean: clean
	rm -f $(NAME)

re: fclean all
