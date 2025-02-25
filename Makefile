# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/17 12:48:47 by joseoliv          #+#    #+#              #
#    Updated: 2025/02/25 06:42:44 by joseoliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

INCLUDE	= -lpthread

SRC = 	src/main.c \
		\
		src/validation_input/validate_args.c \
		\
		src/utils/ft_atoi.c src/utils/time.c \
		\
		src/init/init.c \
		\
		src/mutex/mutex_funcs_1.c src/mutex/mutex_funcs_2.c \
		\
		src/simulation/handle_simulation.c src/simulation/monitoring.c \
		src/simulation/single_philo.c \
		\
		src/threads_handler/last_th_handler.c \

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