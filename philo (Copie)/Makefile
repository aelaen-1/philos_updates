# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelaen <aelaen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 12:57:07 by aboukezi          #+#    #+#              #
#    Updated: 2024/11/13 18:27:12 by aelaen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
FLAGS = -Wall -Werror -Wextra 
# valgrind --tool=helgrind ./multi_thread_loop_mutex

SRC = main.c \
      parsing_init.c \
	  forks.c \
      utils.c \
	  actions.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re