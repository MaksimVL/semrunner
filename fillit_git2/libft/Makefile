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
SRC = ft_atoi.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdup.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c	\
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstmap.c \
		ft_lstiter.c \
		ft_itoa_base.c \
		ft_atoi_base.c \
		ft_lstlen.c \
		ft_sort_str_table.c \
		ft_strcapitalize.c \
		get_next_line.c \
		ft_lstappend.c

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

