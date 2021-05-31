# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/25 16:53:43 by nle-biha          #+#    #+#              #
#    Updated: 2020/11/26 18:12:58 by nle-biha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_atoi.c ft_itoa.c ft_putchar_fd.c ft_strlcat.c ft_substr.c ft_bzero.c ft_putendl_fd.c ft_strlcpy.c ft_tolower.c ft_calloc.c ft_memccpy.c ft_putnbr_fd.c  ft_strlen.c  ft_toupper.c ft_isalnum.c ft_memchr.c ft_putstr_fd.c ft_strmapi.c ft_isalpha.c ft_memcmp.c ft_split.c ft_strncmp.c ft_isascii.c ft_memcpy.c ft_strchr.c ft_strnstr.c ft_isdigit.c ft_memmove.c ft_strdup.c ft_strrchr.c ft_isprint.c ft_memset.c ft_strjoin.c ft_strtrim.c

BONUS = ft_lstadd_back.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstsize.c ft_lstadd_front.c  ft_lstdelone.c  ft_lstlast.c  ft_lstnew.c

OBJSBONUS = ${BONUS:.c=.o}

OBJS = ${SRCS:.c=.o}

NAME = libft.a

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

bonus:	${OBJS} ${OBJSBONUS}
		ar rcs ${NAME} ${OBJS} ${OBJSBONUS}

all:	${NAME}

clean:
	${RM} ${OBJS} ${OBJSBONUS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all
