# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroi <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/14 04:39:27 by aroi              #+#    #+#              #
#    Updated: 2018/07/26 18:36:16 by aroi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror
# HEADER	= -I libft/

SRC		=	main.c \
			fdf_struct.c \
			key_bindings.c

OBJ		=	main.o \
			fdf_struct.o \
			key_bindings.o

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -I /usr/local/include -L /usr/local/lib \
		-lmlx libft/libft.a -framework OpenGL -framework AppKit

clean:
	make -C libft clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft fclean
	rm -rf $(NAME)

re: fclean all