# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbuczyns <gbuczyns@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/05 21:35:42 by gbuczyns          #+#    #+#              #
#    Updated: 2024/07/07 00:55:19 by gbuczyns         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

# Names definition.
INC = -Iinc
INCLUDELIBFT = -Ilib/libft/inc
LIBFT_DIR = ./lib/libft

# The names of programs.
CLIENT_NAME			= client
SERVER_NAME			= server
CLIENT_NAME_BONUS	= client_bonus
SERVER_NAME_BONUS	= server_bonus
LIBFT				= ./lib/libft/libft.a

# Directories
SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = inc/

# The source files names in lists.
SRC_CLIENT = $(addprefix ${SRC_DIR}, client_send_data.c client.c)
SRC_SERVER = $(addprefix ${SRC_DIR}, server.c server_cycle.c)

SRC_CLIENT_BONUS = $(addprefix ${SRC_DIR}, client_send_data.c client_bonus.c)
SRC_SERVER_BONUS = $(addprefix ${SRC_DIR}, server_bonus.c server_cycle_bonus.c)


# Storing object file names in lists.
OBJS_CLIENT			=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC_CLIENT))
OBJS_SERVER			=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC_SERVER))
OBJS_CLIENT_BONUS	=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC_CLIENT_BONUS))
OBJS_SERVER_BONUS	=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC_SERVER_BONUS))

# Commands
all: 		$(CLIENT_NAME) $(SERVER_NAME)
bonus:		$(CLIENT_NAME_BONUS) $(SERVER_NAME_BONUS)

# Compile libft
$(LIBFT):
	$(MAKE) all clean -C $(LIBFT_DIR)

# Compile executables
$(SERVER_NAME): $(OBJS_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $(INC) $(INCLUDELIBFT) $(OBJS_SERVER) $(LIBFT) -o $(SERVER_NAME)
$(CLIENT_NAME): $(OBJS_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $(INC) $(INCLUDELIBFT) $(OBJS_CLIENT) $(LIBFT) -o $(CLIENT_NAME)

$(SERVER_NAME_BONUS): $(OBJS_SERVER_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(INC) $(INCLUDELIBFT) $(OBJS_SERVER_BONUS) $(LIBFT) -o $(SERVER_NAME_BONUS)
$(CLIENT_NAME_BONUS): $(OBJS_CLIENT_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(INC) $(INCLUDELIBFT) $(OBJS_CLIENT_BONUS) $(LIBFT) -o $(CLIENT_NAME_BONUS)
 
# Rule to compile .c files into .o files.
$(OBJ_DIR)%.o:  $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@echo "Compiling $< with includes: $(INC) $(INCLUDELIBFT)"
	$(CC) $(CFLAGS) $(INC) $(INCLUDELIBFT) -c $< -o $@

# Rule to clean object files.
clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	@$(RM) -r $(OBJ_DIR)

# Rule to clean executable + clean.
fclean: clean
		$(MAKE) fclean -C $(LIBFT_DIR)
		$(RM) $(CLIENT_NAME) $(SERVER_NAME) 
		$(RM) $(SERVER_NAME_BONUS) $(CLIENT_NAME_BONUS)

# Rule to rebuild everything.
re: fclean all

# Phony targets
.PHONY: all clean fclean re bonus
