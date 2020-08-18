# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mberglun <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/02 17:10:30 by mberglun          #+#    #+#              #
#    Updated: 2020/02/09 15:37:20 by mikaelber        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

# DIRECTORIES
SRC_DIR = ./srcs/
OBJ_DIR = ./objs/
INC_DIR = ./includes/

# LIBFT source files
SRC_FILES = ft_strlen.c ft_toupper.c ft_tolower.c ft_strcmp.c ft_strncmp.c ft_abs.c \
	ft_intlen.c ft_itoa.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_atoi.c ft_strcat.c ft_strncat.c ft_strstr.c ft_strnstr.c \
	ft_strchr.c ft_strrchr.c ft_strlcat.c ft_strcpy.c ft_strncpy.c ft_strdup.c \
	ft_memccpy.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_memchr.c ft_memcmp.c \
	ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c \
	ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
	ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_putchar.c ft_putstr.c ft_putendl.c \
	ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
	ft_pow.c ft_strndup.c ft_min.c ft_max.c ft_sqrt.c \
	ft_strescape.c ft_strcc.c ft_isspecial.c
# LIBFT header files
HDR_FILES = libft.h

# GNL source files
SRC_FILES += get_next_line.c
# GNL header files
HDR_FILES += gnl.h

# FT_PRINTF source files
SRC_FILES += \
	ft_printf/ft_printf.c \
	ft_printf/parse/parse.c \
	ft_printf/parse/parse_flags.c \
	ft_printf/parse/parse_width.c \
	ft_printf/parse/parse_precision.c \
	ft_printf/parse/parse_length.c \
	ft_printf/parse/parse_specifier.c \
	ft_printf/parse/parse_number.c \
	ft_printf/formatters/format_router.c \
	ft_printf/formatters/format_int.c \
	ft_printf/formatters/format_uint.c \
	ft_printf/formatters/format_hex.c \
	ft_printf/formatters/format_ptr.c \
	ft_printf/formatters/format_octal.c \
	ft_printf/formatters/format_float.c \
	ft_printf/formatters/format_char.c \
	ft_printf/formatters/format_str.c \
	ft_printf/formatters/format_perc.c \
	ft_printf/formatters/format_bin.c \
	ft_printf/formatters/format_width.c \
	ft_printf/utils/number_arguments.c \
	ft_printf/utils/number_utils.c \
	ft_printf/utils/base_conversion.c
# FT_PRINTF header files
HDR_FILES += ft_printf.h ft_printf_types.h

# add dir prefixes
INCS = $(addprefix $(INC_DIR), $(HDR_FILES));
OBJS = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(INCS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(OBJS): $(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
