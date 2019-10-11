# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 12:13:46 by odrinkwa          #+#    #+#              #
#    Updated: 2019/10/09 18:14:31 by odrinkwa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
L_FT 		?= .
FT_NAME		= $(NAME)
HD_NAME		= libft.h

FT_LNK 		= -L $(L_FT) -l ft
FT_INC		= -I $(L_FT)/includes
FT_INC_PRF	= -I $(L_FT)/includes/printf_hdr
FT_LIB		= $(L_FT)/$(FT_NAME)

LIB_LNK		= $(FT_LNK)
LIB_INC		= $(FT_INC)

SRC_DIR		= ./sources/
INC_DIR		= ./includes/
OBJ_DIR		= ./objects/

FULL_HD_NAME	= $(addprefix $(INC_DIR),$(HD_NAME))

LIBFT_SRC	= ft_atoi.c ft_bzero.c ft_dictadd.c ft_dictclearzero.c \
	ft_dictdelbykey.c ft_dictdelelement.c ft_dictgetoraddvalue.c \
	ft_dictgetvalue.c ft_dictnew.c ft_free.c ft_getnbr_base.c ft_isalnum.c \
	ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
	ft_lstadd.c ft_lstaddback.c ft_lstdel.c ft_lstdeli.c ft_lstdelone.c \
	ft_lstfind.c ft_lsti.c ft_lstiter.c ft_lstlen.c ft_lstmap.c \
	ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
	ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_outbuff_dst.c \
	ft_outbuff.c ft_pow.c ft_printstrsplit.c ft_putchar_fd.c ft_putchar.c \
	ft_putendl_fd.c ft_putendl.c ft_putnbr_fd.c ft_putnbr.c ft_putstr_fd.c \
	ft_putstr.c ft_skip_digits.c ft_strcat.c ft_strchr.c ft_strclr.c \
	ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c \
	ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c \
	ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
	ft_strnequ.c ft_strnew.c ft_strnjoin.c ft_strnstr.c ft_strrchr.c \
	ft_strset.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
	ft_tolower.c ft_toupper.c ft_zerostr.c get_next_line.c ft_nbrlen.c

PRINTF_SRC	= arg_mode.c bn_auxfunc.c bn_fix.c bn_fstr.c bn_init.c \
	bn_oppow.c bn_opsub.c bn_opsummul.c bn_outp.c bn_round.c change_fd.c \
	change_outstr.c dbl_input.c double.c extend_dollar.c \
	ft_printf.c get_item_by_size.c global_bak.c handle_comma_flag.c \
	handle_spec.c handle_stars.c print_output.c read_spec.c \
	spectostr_bighex.c spectostr_bin.c spectostr_char.c \
	spectostr_float.c spectostr_lowhex.c spectostr_oct.c \
	spectostr_percent.c spectostr_ptr.c spectostr_sdec.c \
	spectostr_string.c spectostr_udec.c

PRF_DIR		= ./sources/printf_src/

OBJ_PRF_DIR = ./objects/printf_obj/

OBJ_PRF		= $(addprefix $(OBJ_PRF_DIR),$(PRINTF_SRC:.c=.o))

HD_NAME_PRF = ft_options.h ft_outbuff_dst.h ft_outbuff.h ft_printf.h \
	prf_arg_mode.h prf_double.h prf_extend_dollar.h prf_get_item_by_size.h \
	prf_global_bak.h prf_handle_comma_flag.h prf_handle_spec.h \
	prf_handle_stars.h prf_print_output.h prf_printf_spec.h \
	prf_read_spec.h prf_spectostr_funcs.h

INC_DIR_PRF = ./includes/printf_hdr/

FULL_HD_PRF = $(addprefix $(INC_DIR_PRF),$(HD_NAME_PRF))

SRC 		= $(LIBFT_SRC)

OBJ			= $(addprefix $(OBJ_DIR),$(SRC:.c=.o))

OBJ 		+= $(OBJ_PRF)

CFLAGS 		= -Wall -Wextra -Werror -g3
CC			= gcc

.PHONY: all clean fclean re

all: $(OBJ_DIR) $(NAME)

clean:
	rm -rf $(OBJ_PRF_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_PRF_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(FULL_HD_NAME)
	$(CC) $(CFLAGS) $(FT_INC) $(FT_INC_PRF) -o $@ -c $<

$(OBJ_PRF_DIR)%.o: $(PRF_DIR)%.c #$(FULL_HD_PRF)
	$(CC) $(CFLAGS) $(FT_INC) $(FT_INC_PRF) -o $@ -c $<

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

