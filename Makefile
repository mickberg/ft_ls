# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mberglun <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/02 17:10:30 by mberglun          #+#    #+#              #
#    Updated: 2020/02/07 11:51:38 by mikaelber        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = ft_ls

SRC_DIR = ./srcs/
OBJ_DIR = ./objs/
INC_DIR = ./includes/
LIB_DIR = ./libft/

SRC_FILES = ft_ls.c
HDR_FILES = ft_ls.h

LIBFT = $(LIB_DIR)libft.a

INCS = $(addprefix $(INC_DIR), $(HDR_FILES));
OBJS = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

.PHONY: clean fclean re

all: $(NAME)

$(LIBFT):
	@make -C $(LIB_DIR)

$(NAME): $(OBJS) $(LIBFT) $(INCS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I $(INC_DIR) -I $(LIB_DIR) -L$(LIB_DIR) -lft

$(OBJS): $(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR) -I $(LIB_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIB_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_DIR) fclean

re: fclean all
