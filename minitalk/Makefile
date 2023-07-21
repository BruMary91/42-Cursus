# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbrunett <mbrunett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 11:28:30 by dcologgi          #+#    #+#              #
#    Updated: 2023/07/21 12:46:43 by mbrunett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_PRINTF = ./libft/ft_printf/libftprintf.a
LIBFT = ./libft/libft.a

SERVER_SOURCES = server.c
CLIENT_SOURCES = client.c

SERVER_OBJECTS = ${SERVER_SOURCES:.c=.o}
CLIENT_OBJECTS = ${CLIENT_SOURCES:.c=.o}

NAME_SERVER = server
NAME_CLIENT = client

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

%.o:%.c
	${CC} ${CFLAGS} -c $< -o $@

all : ${NAME_SERVER} ${NAME_CLIENT}

${NAME_SERVER}: ${SERVER_OBJECTS} ${FT_PRINTF} ${LIBFT}
				${CC} ${SERVER_OBJECTS} ${FT_PRINTF} ${LIBFT} -o ${NAME_SERVER}

${NAME_CLIENT}: ${CLIENT_OBJECTS} ${FT_PRINTF} ${LIBFT}
				${CC} ${CLIENT_OBJECTS} ${FT_PRINTF} ${LIBFT} -o ${NAME_CLIENT}

${FT_PRINTF}:
				make -C ./libft/ft_printf

${LIBFT}:
				make -C ./libft

clean :
		${RM} ${SERVER_OBJECTS} ${CLIENT_OBJECTS}
		make clean -C ./libft/ft_printf
		make clean -C ./libft

fclean : clean
		rm -f ${NAME_SERVER} ${NAME_CLIENT}
		rm -f ${FT_PRINTF}

re : fclean all
