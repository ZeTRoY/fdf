# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroi <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/14 04:39:27 by aroi              #+#    #+#              #
#    Updated: 2018/07/28 18:47:59 by aroi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror
# HEADER	= -I libft/

SRC		=	main.c \
			fdf_struct.c \
			read.c \
			key_bindings.c \
			draw_info.c \
			draw_intro.c \
			lets_paint.c \
			bresenham_alg.c \
			color.c

OBJ		=	main.o \
			fdf_struct.o \
			read.o \
			key_bindings.o \
			draw_info.o \
			draw_intro.o \
			lets_paint.o \
			bresenham_alg.o \
			color.o

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) -I /usr/local/include -L /usr/local/lib \
		-lmlx libft/libft.a -framework OpenGL -framework AppKit

clean:
	make -C libft clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft fclean
	rm -rf $(NAME)

re: fclean all