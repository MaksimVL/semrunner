# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 12:13:46 by odrinkwa          #+#    #+#              #
#    Updated: 2019/09/15 22:12:20 by odrinkwa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
COMPILERC = gcc
MAKERLIB = ar rc
FLAGS = -Wall -Wextra -Werror
FLAGS1 = -c
SOURCES_DIR = sources/
SOURCES  = ft_atoi.c ft_bzero.c ft_dictadd.c ft_dictclearzero.c \
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
        ft_tolower.c ft_toupper.c
OBJECTS = $(SOURCES:.c=.o)
HEADERS = includes
HEADER = $(HEADERS)/libft.h
all: $(NAME)

$(NAME): $(OBJECTS)
	$(MAKERLIB) $(NAME) $(OBJECTS)
	ranlib $(NAME)

%.o: $(SOURCES_DIR)%.c $(HEADER)
#	$(COMPILERC) -o $@ -c $< $(FLAGS) -I$(HEADERS)
	$(COMPILERC) -o $@ -c $< -I$(HEADERS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)	

re: fclean all
