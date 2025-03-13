# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lupelleg <lupelleg@student.42heilbronn.de  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 13:00:22 by lupelleg          #+#    #+#              #
#    Updated: 2025/03/13 09:43:18 by lupelleg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tester

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = libft_tester.c

LIBFT = ../libft.a

all: $(NAME)

$(NAME): $(SRCS) $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
