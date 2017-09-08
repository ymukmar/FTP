# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymukmar <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/16 15:42:14 by ymukmar           #+#    #+#              #
#    Updated: 2017/09/08 13:05:24 by ymukmar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server
CC = gcc

CLIENT_FOLDER = ./srcs/client
SERVER_FOLDER = ./srcs/server
SRC_FOLDER = ./srcs/

CLIENT_SRC = $(wildcard $(CLIENT_FOLDER)/*.c)
SERVER_SRC = $(wildcard $(SERVER_FOLDER)/*.c)
SHARED_SRC = $(wildcard $(SRC_FOLDER)/*.c)
AUTHOR = author

INCLUDE = -I ./includes
LIB = -L ./libft -lft
FLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a

all: $(CLIENT) $(SERVER) $(AUTHOR) $(LIBFT)

$(CLIENT): $(CLIENT_SRC) $(SHARED_SRC)
	@$(CC) $(FLAGS) $(INCLUDE) $(CLIENT_SRC) $(SHARED_SRC) $(LIB) -o $@

$(SERVER): $(SERVER_SRC) $(SHARED_SRC)
	@$(CC) $(INCLUDE) $(SERVER_SRC) $(SHARED_SRC) $(LIB) -o $@

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
