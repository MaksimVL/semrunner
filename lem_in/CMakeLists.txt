cmake_minimum_required(VERSION 3.15)
project(lem_in C)

set(CMAKE_C_STANDARD 11)

add_custom_target(lem_in
        COMMAND make
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(includes)
include_directories(libft/includes)
include_directories(libft/includes/printf_hdr)

add_executable(lem_in_tmp
        includes/lemin.h
        libft/includes/printf_hdr/ft_options.h
        libft/includes/printf_hdr/ft_outbuff.h
        libft/includes/printf_hdr/ft_outbuff_dst.h
        libft/includes/printf_hdr/ft_printf.h
        libft/includes/printf_hdr/prf_arg_mode.h
        libft/includes/printf_hdr/prf_double.h
        libft/includes/printf_hdr/prf_extend_dollar.h
        libft/includes/printf_hdr/prf_get_item_by_size.h
        libft/includes/printf_hdr/prf_global_bak.h
        libft/includes/printf_hdr/prf_handle_comma_flag.h
        libft/includes/printf_hdr/prf_handle_spec.h
        libft/includes/printf_hdr/prf_handle_stars.h
        libft/includes/printf_hdr/prf_print_output.h
        libft/includes/printf_hdr/prf_printf_spec.h
        libft/includes/printf_hdr/prf_read_spec.h
        libft/includes/printf_hdr/prf_spectostr_funcs.h
        libft/includes/libft.h
        libft/includes/terminal_draw.h
        libft/sources/printf_src/arg_mode.c
        libft/sources/printf_src/bn_auxfunc.c
        libft/sources/printf_src/bn_auxfunc1.c
        libft/sources/printf_src/bn_fix.c
        libft/sources/printf_src/bn_fstr.c
        libft/sources/printf_src/bn_init.c
        libft/sources/printf_src/bn_oppow.c
        libft/sources/printf_src/bn_opsub.c
        libft/sources/printf_src/bn_opsummul.c
        libft/sources/printf_src/bn_outp.c
        libft/sources/printf_src/bn_round.c
        libft/sources/printf_src/change_fd.c
        libft/sources/printf_src/change_outstr.c
        libft/sources/printf_src/dbl_input.c
        libft/sources/printf_src/double.c
        libft/sources/printf_src/extend_dollar.c
        libft/sources/printf_src/ft_printf.c
        libft/sources/printf_src/get_item_by_size.c
        libft/sources/printf_src/global_bak.c
        libft/sources/printf_src/handle_comma_flag.c
        libft/sources/printf_src/handle_spec.c
        libft/sources/printf_src/handle_stars.c
        libft/sources/printf_src/print_output.c
        libft/sources/printf_src/read_spec.c
        libft/sources/printf_src/spectostr_bighex.c
        libft/sources/printf_src/spectostr_bin.c
        libft/sources/printf_src/spectostr_char.c
        libft/sources/printf_src/spectostr_float.c
        libft/sources/printf_src/spectostr_lowhex.c
        libft/sources/printf_src/spectostr_oct.c
        libft/sources/printf_src/spectostr_percent.c
        libft/sources/printf_src/spectostr_ptr.c
        libft/sources/printf_src/spectostr_sdec.c
        libft/sources/printf_src/spectostr_string.c
        libft/sources/printf_src/spectostr_udec.c
        libft/sources/ft_atoi.c
        libft/sources/ft_bzero.c
        libft/sources/ft_del_strsplit.c
        libft/sources/ft_dictadd.c
        libft/sources/ft_dictclearzero.c
        libft/sources/ft_dictdelbykey.c
        libft/sources/ft_dictdelelement.c
        libft/sources/ft_dictgetoraddvalue.c
        libft/sources/ft_dictgetvalue.c
        libft/sources/ft_dictnew.c
        libft/sources/ft_dlist.c
        libft/sources/ft_free.c
        libft/sources/ft_getnbr_base.c
        libft/sources/ft_isalnum.c
        libft/sources/ft_isalpha.c
        libft/sources/ft_isascii.c
        libft/sources/ft_isdigit.c
        libft/sources/ft_isint.c
        libft/sources/ft_isprint.c
        libft/sources/ft_itoa.c
        libft/sources/ft_lstadd.c
        libft/sources/ft_lstaddback.c
        libft/sources/ft_lstdel.c
        libft/sources/ft_lstdeli.c
        libft/sources/ft_lstdelone.c
        libft/sources/ft_lstfind.c
        libft/sources/ft_lsti.c
        libft/sources/ft_lstiter.c
        libft/sources/ft_lstlen.c
        libft/sources/ft_lstmap.c
        libft/sources/ft_lstnew.c
        libft/sources/ft_memalloc.c
        libft/sources/ft_memccpy.c
        libft/sources/ft_memchr.c
        libft/sources/ft_memcmp.c
        libft/sources/ft_memcpy.c
        libft/sources/ft_memdel.c
        libft/sources/ft_memmove.c
        libft/sources/ft_memset.c
        libft/sources/ft_nbrlen.c
        libft/sources/ft_outbuff.c
        libft/sources/ft_outbuff_dst.c
        libft/sources/ft_pow.c
        libft/sources/ft_printstrsplit.c
        libft/sources/ft_putchar.c
        libft/sources/ft_putchar_fd.c
        libft/sources/ft_putendl.c
        libft/sources/ft_putendl_fd.c
        libft/sources/ft_putnbr.c
        libft/sources/ft_putnbr_fd.c
        libft/sources/ft_putstr.c
        libft/sources/ft_putstr_fd.c
        libft/sources/ft_queue.c
        libft/sources/ft_skip_digits.c
        libft/sources/ft_strcat.c
        libft/sources/ft_strchr.c
        libft/sources/ft_strclr.c
        libft/sources/ft_strcmp.c
        libft/sources/ft_strcpy.c
        libft/sources/ft_strdel.c
        libft/sources/ft_strdup.c
        libft/sources/ft_strequ.c
        libft/sources/ft_striter.c
        libft/sources/ft_striteri.c
        libft/sources/ft_strjoin.c
        libft/sources/ft_strlcat.c
        libft/sources/ft_strlen.c
        libft/sources/ft_strmap.c
        libft/sources/ft_strmapi.c
        libft/sources/ft_strncat.c
        libft/sources/ft_strncmp.c
        libft/sources/ft_strncpy.c
        libft/sources/ft_strnequ.c
        libft/sources/ft_strnew.c
        libft/sources/ft_strnjoin.c
        libft/sources/ft_strnstr.c
        libft/sources/ft_strrchr.c
        libft/sources/ft_strset.c
        libft/sources/ft_strsplit.c
        libft/sources/ft_strstr.c
        libft/sources/ft_strsub.c
        libft/sources/ft_strtrim.c
        libft/sources/ft_tolower.c
        libft/sources/ft_toupper.c
        libft/sources/ft_zerostr.c
        libft/sources/get_next_line.c
        sources/initialize.c
        sources/load_map.c
        sources/main.c
        sources/print_room_links_props.c)
