# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/06 19:27:19 by nle-biha          #+#    #+#              #
#    Updated: 2021/06/03 18:58:19 by nle-biha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	fdf
CC		=	clang
FLAGS	=	-O3 -Wall -Wextra
SRCS	=	srcs/get_next_line_utils_bonus.c srcs/get_next_line_bonus.c srcs/main.c srcs/fdf_display.c srcs/draw_lines.c srcs/draw_lines2.c srcs/fdf_utils.c
INCS	=	$(addprefix includes/, fdf.h)
OBJS	=	$(SRCS:.c=.o)


all: $(NAME)


$(NAME): $(OBJS) $(INCS)
	make -C libft
	make -C mlx_linux
	$(CC) $(FLAGS) -I includes -o $(NAME) $(OBJS) -Llibft -lft -Lmlx_linux -lmlx_Linux -lX11 -lbsd -lm -lXext

%.o: %.c $(INCS)
	$(CC) $(FLAGS) -I includes -Imlx_linux -c $< -o $@

clean:
	@make fclean -C libft
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all
