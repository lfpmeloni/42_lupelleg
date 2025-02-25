NAME = rush-02

SRC = main.c logic.c convert_number.c convert_hundreds.c dict_handling.c helper.c

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
