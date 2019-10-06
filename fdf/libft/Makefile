# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 12:13:46 by odrinkwa          #+#    #+#              #
#    Updated: 2019/10/05 12:25:34 by semenbegunov     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
L_FT 		?= .
FT_NAME		= $(NAME)
HD_NAME		= libft.h

FT_LNK 		= -L $(L_FT) -l ft
FT_INC		= -I $(L_FT)/includes
FT_LIB		= $(L_FT)/$(FT_NAME)

LIB_LNK		= $(FT_LNK)
LIB_INC		= $(FT_INC)

SRC_DIR		= ./sources/
INC_DIR		= ./includes/
OBJ_DIR		= ./objects/

FULL_HD_NAME	= $(addprefix $(INC_DIR),$(HD_NAME))
LIBFT_SRC	= ft_atoi.c ft_bzero.c ft_dictadd.c ft_dictclearzero.c \
        ft_dictdelbykey.c ft_dictdelelement.c ft_dictgetoraddvalue.c \
        ft_dictgetvalue.c ft_dictnew.c ft_isalnum.c ft_isalpha.c \
        ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c \
        ft_lstaddback.c ft_lstdel.c ft_lstdeli.c ft_lstdelone.c ft_lsti.c \
        ft_lstiter.c ft_lstlen.c ft_lstmap.c ft_lstnew.c ft_memalloc.c \
        ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c \
        ft_memmove.c ft_memset.c ft_printstrsplit.c ft_putchar.c \
        ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
        ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c \
        ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c \
        ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
        ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
        ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnjoin.c ft_strnstr.c \
        ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
        ft_tolower.c ft_toupper.c get_next_line.c
SRC 		= $(LIBFT_SRC)

OBJ			= $(addprefix $(OBJ_DIR),$(SRC:.c=.o))

CFLAGS 		= -Wall -Wextra -Werror -g3
CC			= gcc

.PHONY: all clean fclean re

all: $(OBJ_DIR) $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(FULL_HD_NAME)
	$(CC) $(CFLAGS) $(FT_INC) -o $@ -c $<

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

