# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 12:13:46 by odrinkwa          #+#    #+#              #
#    Updated: 2019/09/17 23:26:52 by odrinkwa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
COMPILERC = gcc
MAKERLIB = ar rc
FLAGS = -Wall -Wextra -Werror
FLAGS1 = -c
SOURCES_DIR = sources/
SOURCES  = main.c read.c slv_auxf.c slv_tetr.c
SOURCESLIB = libft/libft.a
OBJECTS = $(SOURCES:.c=.o)
HEADERS = includes
HEADERSLIB = libft/includes

all: $(NAME)

$(NAME): $(OBJECTS)
	gcc -o $(NAME) $(OBJECTS) -I includes -L libft/ -lft

%.o: $(SOURCES_DIR)%.c
	gcc -o $@ -c $< $(FLAGS) -I$(HEADERS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)	

re: fclean all