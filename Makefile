# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/17 12:48:47 by joseoliv          #+#    #+#              #
#    Updated: 2025/02/05 20:29:59 by joseoliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc -g

INCLUDE	= -lpthread

SRC = 	src/main.c \
		\
		src/utils/ft_atoi.c \
		\
		src/validation_input/validate_args.c \

OBJ = $(SRC:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(INCLUDE) -o $@ $(OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

leaks:
	valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --log-file=output.log ./philo

re: fclean all