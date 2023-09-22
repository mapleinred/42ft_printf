# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xzhang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/18 16:15:30 by xzhang            #+#    #+#              #
#    Updated: 2023/09/22 09:06:46 by xzhang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_itoa.c ft_pinthex.c ft_ppointer.c ft_printf.c ft_putchar.c \
	  ft_putstr.c ft_strdup.c ft_strlen.c ft_uitoa.c
	  

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a
LIBC	= ar rc
CC	= gcc
RM	= rm -f
CFLAGS	= -Wall -Wextra -Werror

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
