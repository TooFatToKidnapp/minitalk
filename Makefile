# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabdou <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/19 23:03:01 by aabdou            #+#    #+#              #
#    Updated: 2022/02/19 23:03:04 by aabdou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


HEADER	=	 minitalk.h

M_SRC	=	ft_util.c \
			ft_client.c\

M_SRC2	= 	ft_util.c \
			ft_server.c \

M_OBJ	= 	$(M_SRC:.c=.o)
M_OBJ2	= 	$(M_SRC2:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror

all: server client 
	$(CC) $(FLAGS) $(M_OBJ2) -o server
	$(CC) $(FLAGS) $(M_OBJ) -o client

client:$(M_SRC)
	$(CC) $(FLAGS) $(M_SRC) -c

server:$(M_SRC2)
	$(CC) $(FLAGS) $(M_SRC2) -c
 
clean:
	rm *.o

fclean:clean
	rm client server

re : fclean all
