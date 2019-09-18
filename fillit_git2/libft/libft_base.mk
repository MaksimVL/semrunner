# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_base.mk                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 15:24:49 by hwolf             #+#    #+#              #
#    Updated: 2019/09/19 00:11:37 by odrinkwa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



# Base variables for libft
# Use with 'include /path/to/libft.mk'
# Make sure to define L_FT with path to libft first

L_FT		?= .

FT_NAME		:= libft.a
HD_NAME		:= libft.h

FT_LNK		:= -L $(L_FT) -l ft
FT_INC		:= -I $(L_FT)
FT_LIB		:= $(L_FT)/$(FT_NAME)

# Global variables for compilation

ifndef LIB_LNK
LIB_LNK		:=
LIB_INC		:=
endif

LIB_LNK		+= $(FT_LNK)
LIB_INC		+= $(FT_INC)