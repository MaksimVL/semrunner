# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 15:24:49 by hwolf             #+#    #+#              #
#    Updated: 2019/09/19 00:55:35 by odrinkwa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include libft_base.mk

SRC_DIR = ./
INC_DIR = ./
OBJ_DIR = ./
SRC = $(LIBFT_SRC)

OBJ = $(addprefix $(OBJ_DIR),$(SRC:.c=.o))
CFLAGS = -Wall -Wextra -Werror
CC = gcc

.PHONY: all clean fclean re

all: $(FT_NAME)


$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c $(HD_NAME)
	$(CC) $(CFLAGS) $(FT_INC) -o $@ -c $<

$(FT_NAME): $(OBJ)
	ar rc $(FT_NAME) $(OBJ)
	ranlib $(FT_NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(FT_NAME)

re:
	$(MAKE) fclean --no-print-directory
	$(MAKE) all --no-print-directory

