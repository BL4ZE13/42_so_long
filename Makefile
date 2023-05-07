# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 14:01:06 by diomarti          #+#    #+#              #
#    Updated: 2023/05/07 20:51:26 by diomarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS_NAME =	main.c \
			keys.c \
			moves.c \
			close_game.c \
			map.c \
			check_map.c \
			get_next_line_utils.c \
			get_next_line.c \
			put_images.c 

CC = gcc
CFLAGS = -Wall -Werror -Wextra -Imlx -g -fsanitize=address
MILIB = -I /usr/X11/include -g -L /usr/X11/lib -l minilibx -framework OpenGL -framework AppKit

MLX_LIB_DIR = mlx_linux/
MLX_INCLUDE = -I mlx_linux/

LMLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -fPIC
RM = rm -rf

HEADER = so_long.h

LIBFT = ./libft/libft.a
LIBFT_PATH = ./libft

INC = -Iincludes -I/usr/include -Imlx_linux

SRC_PATH = ./src

OBJ_PATH = ./objects

OBJS = $(addprefix $(OBJ_PATH)/, $(SRCS_NAME:.c=.o))

SRC = $(addprefix $(SRC_PATH)/, $(SRCS_NAME))

all: $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
		make -s -C mlx_linux/
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(INC) $(LMLX_FLAGS) $(MLX_INCLUDE) -o $(NAME)

$(LIBFT):  $(shell make -C $(LIBFT_PATH) -q)
	make -C$(LIBFT_PATH)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c $(MLX_LIB)
	mkdir -p objects
	$(CC) -c $(CFLAGS) $(LMLX_FLAGS) $(INC) $(MLX_INCLUDE)  $< -o $@

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

