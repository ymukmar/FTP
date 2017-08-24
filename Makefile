# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymukmar <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/16 15:42:14 by ymukmar           #+#    #+#              #
#    Updated: 2017/08/24 11:33:24 by ymukmar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server
CC = gcc

CLIENT_FOLDER = ./srcs/client
SERVER_FOLDER = ./srcs/server

CLIENT_SRC = $(wildcard $(CLIENT_FOLDER)/*.c)
SERVER_SRC = $(wildcard $(SERVER_FOLDER)/*.c)
AUTHOR = author

INCLUDE = -I ./includes
LIB = -L ./libft -lft
FLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a

all: $(CLIENT) $(AUTHOR) $(LIBFT)

$(CLIENT): $(CLIENT_SRC)
	@$(CC) $(FLAGS) $(INCLUDE) $(CLIENT_SRC) $(LIB) -o $@

$(SERVER): $(SERVER_SRC)
	@$(CC) $(FLAGS) $(INCLUDE) $(SERVER_SRC) $(LIB) -o $@

$(AUTHOR):
	@echo ymukmar > $@

$(LIBFT):
	@make -C ./libft

clean:
	@make clean -C ./libft
	@rm $(CLIENT) $(SERVER)

fclean: clean
	@make fclean -C ./libft

re: fclean all

.PHONY: re fclean clean all
