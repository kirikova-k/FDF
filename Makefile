# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/12 11:23:22 by ogarthar          #+#    #+#              #
#    Updated: 2021/10/18 12:46:54 by ogarthar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIST =		main.c\
			read_file.c\
			utils.c\
			draw.c\
			draw_utils.c

OBJ = $(LIST:.c=.o)

MLX =	./minilibx_macos/libmlx.a

MLX_DIR =	./minilibx_macos

LIBFT_DIR =	./libft

LIBFT =	./libft/libft.a

CC = gcc

FRAEMWORKS = -framework OpenGL -framework AppKit

CFLAGS = -Wall -Werror -Wextra -g -O3

%.o:  %.c fdf.h Makefile minilibx_macos/mlx.h
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

# COLORS
GREEN = \033[1;32m
RED = \033[1;31m
WHITE = \033[0;37m

all : $(NAME)

	@echo "$(GREEN)FDF : ✅ D O N E ✅$(WHITE)"

$(NAME):	$(OBJ) $(MLX) $(LIBFT) Makefile
	$(CC) $(CFLAGS) $(MLX) $(FRAEMWORKS) $(OBJ) $(LIBFT) -o $(NAME)

.FORCE :
$(MLX): .FORCE
	make -C $(MLX_DIR)
	@echo "$(GREEN)MLX : ✅ D O N E ✅$(WHITE)"

$(LIBFT): .FORCE
	make -C $(LIBFT_DIR)
	@echo "$(GREEN)LIBFT : ✅ D O N E ✅$(WHITE)"

re : fclean all

bonus : all

clean :
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	@echo "$(RED)MLX : 💣 D E L E T E D 💣$(WHITE)"
	rm -f $(OBJ)

fclean : clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "$(RED)LIBFT : 💣 D E L E T E D 💣$(WHITE)"
	rm -f $(NAME)
	@echo "$(RED)FDF: 💣 D E L E T E D 💣$(WHITE)"

.PHONY : all clean fclean re bonus
