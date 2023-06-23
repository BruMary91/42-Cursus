# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbrunett <mbrunett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 11:41:09 by mbrunett          #+#    #+#              #
#    Updated: 2023/03/04 15:28:15 by mbrunett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isdigit.c ft_memset.c ft_isprint.c ft_strlen.c ft_memmove.c ft_putchar_fd.c\
ft_atoi.c ft_itoa.c ft_putendl_fd.c ft_split.c ft_strlcat.c ft_strlcpy.c ft_tolower.c\
ft_bzero.c ft_putnbr_fd.c ft_substr.c ft_toupper.c ft_calloc.c ft_memchr.c ft_putstr_fd.c\
ft_strmapi.c ft_isalnum.c ft_memcmp.c ft_strncmp.c ft_isalpha.c ft_memcpy.c ft_strchr.c\
ft_strjoin.c ft_strnstr.c ft_isascii.c ft_strdup.c ft_strrchr.c ft_striteri.c ft_strtrim.c\

OBJS = ${SRCS:.c=.o}

CC = gcc
RM = rm -f

CFLAG = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAG} -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re