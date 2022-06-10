# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chorse <chorse@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/05 12:59:37 by chorse            #+#    #+#              #
#    Updated: 2022/06/07 18:15:29 by chorse           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = split.c main.c ft_sort_three.c ft_check.c ft_begin.c ft_atoi.c others.c butterfly.c ft_lstsize.c ft_sort_five.c functions.c

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
	rm -f $(OBJS)
	rm -f ${DEPS}

fclean: clean 
	rm -f $(NAME)

re: fclean all

-include ${DEPS}