# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 12:13:46 by odrinkwa          #+#    #+#              #
#    Updated: 2019/09/19 01:14:50 by odrinkwa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
NAME1 = fillit1

SRC_DIR := ./fillit_proj
INC_DIR := ./fillit_proj
OBJ_DIR := ./fillit_proj
LIB_DIR := ./libft

SRC  := main.c read.c slv_auxf.c slv_tetr.c analyse.c
HDRS := fillit_proj/fillit.h fillit_proj/slv_tetr.h
OBJ  := $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
OBJECTS = $(SOURCES:.c=.o)

CC := gcc
CFLAGS := -Wall -Wextra -Werror

L_FT := libft

include $(L_FT)/libft_base.mk

SRC_LIB = $(addprefix $(L_FT)/,$(LIBFT_SRC))
HEADER_LIB = $(L_FT)/libft.h

.PHONY: all clean fclean re

all: $(NAME)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(LIB_INC) -I $(INC_DIR) -o $@ -c $<
	
$(NAME): $(OBJ) $(SRC_LIB) $(HEADER_LIB) $(HDRS)
	@$(MAKE) -C $(L_FT)
	$(CC) $(CFLAGS) $(OBJ) $(LIB_LNK) -o $(NAME)

clean:
	rm -rf $(OBJ)
	$(MAKE) -C libft clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(L_FT) fclean

re: fclean all
