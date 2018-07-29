# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroi <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/14 04:39:27 by aroi              #+#    #+#              #
#    Updated: 2018/07/29 11:23:30 by aroi             ###   ########.fr        #
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
	@$(CC) $(FLAGS) -c -o $@ $<
	@echo "\033[32m...Making some magic...\033[0m"

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[32mCrafting \033[1mlibprintf.a\033[0m\033[32m...\033[0m"
	@make -C libft
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME) -I /usr/local/include -L /usr/local/lib \
	-lmlx libft/libft.a -framework OpenGL -framework AppKit
	@echo "\033[1;32m$(NAME)\033[0m\033[32m is ready to use!\033[0m"

clean:
	@make -C libft clean
	@rm -rf $(OBJ)
	@echo "\033[31mRemoving object files...\033[0m"

fclean: clean
	@make -C libft fclean
	@rm -rf $(NAME)
	@echo "\033[31mRemoved \033[1mlibprintf.a\033[0m\033[31m \
	and \033[1m$(NAME)\033[0m\033[31m files.\033[0m"

re: fclean all