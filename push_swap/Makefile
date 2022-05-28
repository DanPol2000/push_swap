# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chorse <chorse@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/05 12:59:37 by chorse            #+#    #+#              #
#    Updated: 2022/03/08 13:18:03 by chorse           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = split.c main.c ft_sort_three.c ft_check.c ft_begin.c ft_atoi.c others.c ft_radix.c ft_lstsize.c ft_sort_five.c functions.c

OBJS = $(SRCS:.c=.o)

DEPS = $(SRCS:.c=.d)

HEADER = push_swap.h

CC = gcc

FLAGS = -Wall -Wextra -Werror -MMD

%.o: %.c
	${CC} ${FLAGS} -c $< -o $@

$(NAME) : $(OBJS)
	${CC} ${FLAGS} $(OBJS) -o $(NAME)

all: ${NAME} 

clean:
	rm -f $(OBJS) ${DEPS}

fclean: clean 
	rm -f $(NAME) ${DEPS}

re: fclean all

-include ${DEPS}