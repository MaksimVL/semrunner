# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 12:13:46 by odrinkwa          #+#    #+#              #
#    Updated: 2019/10/14 18:36:28 by odrinkwa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_DIR := ./sources
INC_DIR := ./includes
INCMLX_DIR := ./mlx
INCLIBFT_DIR := ./libft/includes
OBJ_DIR := ./objects
LIB_DIR := ./libft

SRC  := main.c make_map_points.c initialize_mlx.c readfile0.c readfile1.c \
	readfile2.c draw.c color.c rotation.c \
	get_proj_point.c legend.c keyhook.c draw_surface.c draw_point.c \
	iso_transform.c
HDRS := includes/fdf.h
OBJ  := $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
OBJECTS = $(SOURCES:.c=.o)

CC := gcc
CFLAGS := -Wall -Wextra -Werror -g3
MLXPARAMS := -L ./mlx -lmlx -framework OpenGL -framework AppKit
LIBFT_NODEBUG :=

L_FT := libft

include $(L_FT)/libft_base.mk
TMP = $(subst ./, /, $(ALL_LIBFT))
FULL_ALL_LIBFT = $(addprefix $(L_FT),$(TMP))

SRC_LIB = $(addprefix $(L_FT)/,$(LIBFT_SRC))

HEADER_LIB = $(INCLIBFT_DIR)/libft.h

.PHONY: all clean fclean re

all: $(OBJ_DIR) $(NAME)

test:
	@echo $(FULL_ALL_LIBFT)

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
	$(CC) $(CFLAGS) $(LIB_INC) -I $(INC_DIR) -I $(INCLIBFT_DIR) -I $(INCMLX_DIR) -o $@ -c $<

$(NAME): $(OBJ) $(HEADER_LIB) $(HDRS) $(FULL_ALL_LIBFT)
	$(MAKE) -C $(L_FT) $(LIBFT_NODEBUG)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -I $(INCLIBFT_DIR) -I $(INCMLX_DIR) -L libft -lft $(MLXPARAMS)

nodebug: CFLAGS = -Wall -Wextra -Werror -O3

nodebug: LIBFT_NODEBUG = nodebug

nodebug: fclean all
