# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: misung <misung@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 23:04:05 by misung            #+#    #+#              #
#    Updated: 2021/09/28 00:28:26 by misung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
SRCS	= srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c srcs/ft_swap.c
INCS	= includes/
OBJS	= ${SRCS:.c=.o}
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

.c.o:	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${INCS}
$(NAME):${OBJS}
	ar rc ${NAME} ${OBJS}

all:	${NAME}
clean:	${RM} ${OBJS}
fclean:	clean ${RM} ${NAME}
re:		fclean all
