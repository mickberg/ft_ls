# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mberglun <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/02 17:10:30 by mberglun          #+#    #+#              #
#    Updated: 2020/08/17 23:12:24 by mikaelber        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = ft_ls

SRC_DIR = ./srcs/
OBJ_DIR = ./objs/
INC_DIR = ./includes/
LIB_DIR = ./libft/

SRC_FILES = \
	ft_ls.c \
	list_dir.c \
	print/print.c \
	print/print_modes.c \
	print/print_long.c \
	print/print_col.c \
	utils/entries.c \
	utils/common.c \
	utils/db.c
HDR_FILES = ft_ls.h

LIBFT = $(LIB_DIR)libft.a

INCS = $(addprefix $(INC_DIR), $(HDR_FILES));
OBJS = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

.PHONY: clean fclean re

all: $(NAME)

$(LIBFT):
	@make -C $(LIB_DIR)

$(NAME): $(OBJS) $(LIBFT) $(INCS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I $(INC_DIR) -I $(LIB_DIR) -I $(LIB_DIR)/includes -L$(LIB_DIR) -lft

$(OBJS): $(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR) -I $(LIB_DIR) -I $(LIB_DIR)/includes

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIB_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_DIR) fclean

re: fclean all
