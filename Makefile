# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/05 16:27:42 by joao-ppe          #+#    #+#              #
#    Updated: 2023/09/05 16:27:43 by joao-ppe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -f
DEPS = include/minitalk.h
 
SRC_S = src/server.c 
SRC_C = src/client.c 

BNS_S = server_bonus.c
BNS_C = client_bonus.c

OBJ_S = $(SRC_S:.c=.o)
OBJ_C = $(SRC_C:.c=.o)

OBJ_BNS_S = $(BNS_S:.c=.o)
OBJ_BNS_C = $(BNS_C:.c=.o)

NAME = minitalk

LIBFT = libs/libft/libft.a

all: $(NAME)

$(NAME): $(OBJ_S) $(OBJ_C) $(DEPS)
	$(MAKE) -C libs/libft
	@$(CC) $(OBJ_S) $(LIBFT) -o server
	@$(CC) $(OBJ_C) $(LIBFT) -o client

clean:
	$(MAKE) clean -C libs/libft
	@$(RM) $(OBJ_S) $(OBJ_C) $(OBJ_BNS_S) $(OBJ_BNS_C)

fclean: clean
	@$(RM) $(LIBFT) $(NAME) server client server_bonus client_bonus
	
bonus:$(OBJ_BNS_S) $(OBJ_BNS_C) $(DEPS)
	$(MAKE) -C ./libft
	@$(CC) $(OBJ_BNS_S) $(LIBFT) -o server_bonus
	@$(CC) $(OBJ_BNS_C) $(LIBFT) -o client_bonus
	
	
re: fclean $(NAME)