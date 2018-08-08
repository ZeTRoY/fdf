# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroi <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/14 04:39:27 by aroi              #+#    #+#              #
#    Updated: 2018/08/07 12:43:57 by aroi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf
OS			=	$(shell uname)

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
HEADER		=	-I libft/includes -I ./includes

ifeq ($(OS), Linux)
FLAGS_PLUS	= -L ./minilibx -lmlx -lm -lXext -lX11
HEADER_MLX	= -I ./minilibx
else
FLAGS_PLUS	= -L ./minilibx_macos -lmlx -framework OpenGL -framework AppKit
HEADER_MLX	= -I ./minilibx_macos
endif

FILES		=	main \
				fdf_struct \
				read \
				key_bindings \
				draw_info \
				draw_intro \
				lets_paint \
				bresenham_alg \
				color

SRC			=	$(addprefix src/, $(addsuffix .c, $(FILES)))
OBJ			=	$(addprefix obj/, $(addsuffix .o, $(FILES)))

obj/%.o: src/%.c
	@$(CC) $(FLAGS) -c -o $@ $< $(HEADER) $(HEADER_MLX)
	@echo "\033[32m...Making some magic...\033[0m"

all: $(NAME)


$(NAME): libft/libft.a mlx $(OBJ)
	@make -C libft
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(FLAGS_PLUS) -L libft -lft
	@echo "\033[32m[ ✔ ]\033[1m $(NAME)\033[0m\033[32m is ready to use!\033[0m"

libft/libft.a:
	@echo "\033[32mCrafting \033[1mlibft.a\033[0m\033[32m...\033[0m"
	@make -C libft

ifeq ($(OS), Linux)
mlx:
	@make -C minilibx
else
mlx:
	@make -C minilibx_macos
endif


clean: clean_mlx
	@make -C libft clean
	@rm -rf $(OBJ)
	@echo "\033[31mRemoving object files...\033[0m"

ifeq ($(OS), Linux)
clean_mlx:
	@make -C minilibx clean
else
clean_mlx:
	@make -C minilibx_macos clean
endif

fclean: clean_mlx
	@make -C libft fclean
	@rm -rf $(OBJ)
	@rm -rf $(NAME)
	@echo "\033[31mRemoved \033[1m$(NAME)\033[0m\033[31m file.\033[0m"


re: fclean all

.PHONY: all clean
.NOTPARALLEL: all $(NAME) libft/libft.a mlx clean clean_mlx fclean re
