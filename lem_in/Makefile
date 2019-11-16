# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 12:13:46 by odrinkwa          #+#    #+#              #
#    Updated: 2019/11/16 20:06:47 by odrinkwa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in #TODO не забыть проверить название программы (lem-in ?)

SRC_DIR := ./sources
INC_DIR := ./includes
INCMLX_DIR := ./fdf/mlx
INCLIBFT_DIR := ./libft/includes
OBJ_DIR := ./objects
LIB_DIR := ./libft

SRC  := main.c initialize.c load_map.c load_map1.c destroy.c \
	auxf.c visual.c calc_ways.c solve.c bfs.c prepare_data.c \
	prepare_data1.c prepare_data2.c going_ants.c going_ants1.c


HDRS := includes/lemin.h
OBJ  := $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
OBJECTS = $(SOURCES:.c=.o)


FDF_SRC_DIR := ./fdf/sources
FDF_HDR_DIR := ./fdf/includes
FDF_OBJ_DIR := ./fdf/objects

FDF_SRC := fdf_color.c fdf_draw_point.c fdf_draw.c fdf_get_proj_point.c \
	fdf_initialize_mlx.c fdf_iso_transform.c fdf_rotation.c \
	fdf_make_map_points.c fdf_keyhook.c draw_surface.c \
	fdf_draw_figures.c legend.c

FDF_HDR := ./fdf/includes/fdf.h

FDF_OBJ := $(FDF_SRC:.c=.o)
FDF_OBJ_WITH_PATH := $(addprefix $(FDF_OBJ_DIR)/, $(FDF_OBJ))


CC := gcc
CFLAGS := -g3 -Wall -Wextra #-Werror
MLXPARAMS := -L ./fdf/mlx -lmlx -framework OpenGL -framework AppKit
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
	rm -rf $(FDF_OBJ_DIR)
	$(MAKE) -C libft clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(L_FT) fclean

re: fclean all


$(FDF_OBJ_DIR):
	mkdir -p $(FDF_OBJ_DIR)

$(FDF_OBJ_DIR)/%.o:$(FDF_SRC_DIR)/%.c $(FDF_HDR)
#	$(CC) $(CFLAGS) $(LIB_INC) -I $(INC_DIR) -I $(INCLIBFT_DIR) -o $@ -c $<
	$(CC) $(CFLAGS) $(LIB_INC) -I $(FDF_HDR_DIR) -I $(INCLIBFT_DIR) -I $(INCMLX_DIR) -o $@ -c $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c $(HDRS)
#	$(CC) $(CFLAGS) $(LIB_INC) -I $(INC_DIR) -I $(INCLIBFT_DIR) -o $@ -c $<
	$(CC) $(CFLAGS) $(LIB_INC) -I $(INC_DIR) -I $(INCLIBFT_DIR) -I $(FDF_HDR_DIR) -I $(INCMLX_DIR) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJ) $(HEADER_LIB) $(HDRS) $(FULL_ALL_LIBFT) $(FDF_OBJ_DIR) $(FDF_OBJ_WITH_PATH)
	$(MAKE) -C $(L_FT) $(LIBFT_NODEBUG)
#	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -I $(INCLIBFT_DIR) -L libft -lft
	$(CC) $(CFLAGS) $(OBJ) $(FDF_OBJ_WITH_PATH) -o $(NAME) -I $(INCLIBFT_DIR) -I $(INCMLX_DIR) -L libft -lft $(MLXPARAMS)


nodebug: CFLAGS = -Wall -Wextra -O3 #-Werror

nodebug: LIBFT_NODEBUG = nodebug

nodebug: fclean all
