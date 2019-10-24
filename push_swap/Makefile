# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 12:13:46 by odrinkwa          #+#    #+#              #
#    Updated: 2019/10/24 21:56:05 by odrinkwa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_CHECKER = checker

SRC_DIR := ./sources
INC_DIR := ./includes
#INCMLX_DIR := ./mlx
INCLIBFT_DIR := ./libft/includes
OBJ_DIR := ./objects
LIB_DIR := ./libft

SRC  := main.c stack.c stack_operations.c sort_operations.c \
	stack_draw_term.c stack_operations1.c stack_operations2.c \
	stack_initialize.c stack_rotate.c stack_basic_operations.c \
	stack_print_basic.c stack_rotate_to_top.c \
	stack_rotate_to_bottom.c stack_rotate_for_insert.c \
	stack_array_int.c stack_basic_operations1.c \
	sort_operations1.c sort_main.c sort_first_group.c \
	stack_check.c

HDRS := includes/push_swap.h includes/terminal_draw.h
OBJ  := $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
OBJECTS = $(SOURCES:.c=.o)

CC := gcc
CFLAGS := -g3 -Wall -Wextra -Werror
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

$(NAME): $(OBJ) $(HEADER_LIB) $(HDRS) $(FULL_ALL_LIBFT)
	$(MAKE) -C $(L_FT) $(LIBFT_NODEBUG)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -I $(INCLIBFT_DIR) -L libft -lft
#	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -I $(INCLIBFT_DIR) -I $(INCMLX_DIR) -L libft -lft $(MLXPARAMS)

nodebug: CFLAGS = -Wall -Wextra -Werror -O3

nodebug: LIBFT_NODEBUG = nodebug

nodebug: fclean all
