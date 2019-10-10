# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 12:13:46 by odrinkwa          #+#    #+#              #
#    Updated: 2019/10/09 18:14:31 by odrinkwa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_DIR := ./
INC_DIR := ./includes
INCLIBFT_DIR := ./libft/includes
OBJ_DIR := ./objects
LIB_DIR := ./libft

SRC  := main.c drawline.c initialize_mlx.c
HDRS := includes/fdf.h
OBJ  := $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
OBJECTS = $(SOURCES:.c=.o)

CC := gcc
CFLAGS := -Wall -Wextra -Werror -g3
MLXPARAMS := -I /mlx -L ./mlx -lmlx -framework OpenGL -framework AppKit

L_FT := libft

#include $(L_FT)/libft_base.mk

SRC_LIB = $(addprefix $(L_FT)/,$(LIBFT_SRC))

HEADER_LIB = $(INCLIBFT_DIR)/libft.h

.PHONY: all clean fclean re

all: $(OBJ_DIR) $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C libft clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(L_FT) fclean

re: fclean all

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c $(HDRS)
	$(CC) $(CFLAGS) $(LIB_INC) -I $(INC_DIR) -I $(INCLIBFT_DIR) -o $@ -c $<

$(NAME): $(OBJ) $(HEADER_LIB) $(HDRS)
	$(MAKE) -C $(L_FT)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -I $(INCLIBFT_DIR) -L libft -lft $(MLXPARAMS)
