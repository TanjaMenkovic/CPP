NAME = HiThisIsBrain

BUILD_FLAGS = -Wall -Wextra -std=c++98 -Werror

SRC =

H =

SRC_SUFF = $(addsuffix .cpp, $(SRC))
HEADER_SUFF = $(addsuffix .hpp, $(H))

SRCSO = $(addsuffix .o, $(SRC))

.PHONY: all clean fclean re
all: $(NAME)

$(NAME): main.cpp
	c++ $(BUILD_FLAGS) main.cpp -o $(NAME)

clean:
	rm -f $(SRCSO)

fclean: clean
	rm -f $(NAME)

re: fclean all
