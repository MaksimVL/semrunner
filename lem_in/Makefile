# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 12:13:46 by odrinkwa          #+#    #+#              #
#    Updated: 2019/10/26 19:02:34 by odrinkwa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in #TODO не забыть проверить название программы (lem-in ?)

SRC_DIR := ./sources
INC_DIR := ./includes
#INCMLX_DIR := ./mlx
INCLIBFT_DIR := ./libft/includes
OBJ_DIR := ./objects
LIB_DIR := ./libft

SRC  := main.c initialize.c load_map.c print_room_links_props.c

HDRS := includes/lemin.h
OBJ  := $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
OBJECTS = $(SOURCES:.c=.o)

CC := gcc
CFLAGS := -g3 #-Wall -Wextra -Werror
#MLXPARAMS := -L ./mlx -lmlx -framework OpenGL -framework AppKit
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
	$(CC) $(CFLAGS) $(LIB_INC) -I $(INC_DIR) -I $(INCLIBFT_DIR) -o $@ -c $<
#	$(CC) $(CFLAGS) $(LIB_INC) -I $(INC_DIR) -I $(INCLIBFT_DIR) -I $(INCMLX_DIR) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJ) $(HEADER_LIB) $(HDRS) $(FULL_ALL_LIBFT)
	$(MAKE) -C $(L_FT) $(LIBFT_NODEBUG)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -I $(INCLIBFT_DIR) -L libft -lft
#	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -I $(INCLIBFT_DIR) -I $(INCMLX_DIR) -L libft -lft $(MLXPARAMS)


nodebug: CFLAGS = -Wall -Wextra -Werror -O3

nodebug: LIBFT_NODEBUG = nodebug

nodebug: fclean all
