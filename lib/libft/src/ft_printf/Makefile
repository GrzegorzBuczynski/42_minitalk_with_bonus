# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbuczyns <gbuczyns@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/10 18:56:40 by gbuczyns          #+#    #+#              #
#    Updated: 2024/05/26 01:54:01 by gbuczyns         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRC		=	ft_printf.c ft_print_digit.c ft_print_hexl.c ft_print_hexu.c \
			ft_print_pointer.c ft_print_string.c ft_print_unsigned.c

					
OBJ		=	$(SRC:.c=.o)

CC		= 	cc
FLAGS	=	-Wall -Werror -Wextra

%o:%c
	$(CC) $(FLAGS) -g -c $< -o $@

${NAME}:${OBJ}
	ar rcs ${NAME} ${OBJ}

all :	${NAME}

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re :	fclean	all
