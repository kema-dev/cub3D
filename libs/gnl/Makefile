# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/23 12:30:03 by jjourdan          #+#    #+#              #
#    Updated: 2021/01/26 13:18:01 by jjourdan         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# *******************************    POST-IT    ****************************** #
#                                                                              #
#			## $@ 	Le nom de la cible										   #
#			## $< 	Le nom de la première dépendance						   #
#			## $^ 	La liste des dépendances								   #
#			## $? 	La liste des dépendances plus récentes que la cible		   #
#			## $* 	Le nom du fichier sans suffixe							   #
#                                                                              #
# **************************************************************************** #

CC			=	gcc

RM			=	rm -f

FLAGS		=	-Wall -Wextra -Werror -D BUFFER_SIZE=64

NAME		=	libgnl.a

SRC			=	get_next_line.c \
				get_next_line_utils.c

OBJ			=	$(SRC:.c=.o)

all:			$(NAME)

$(NAME): $(OBJ)
		ar rcs $(NAME) $?

%.o: %.c		get_next_line.h
		$(CC) $(FLAGS) -c $< -o $@

clean:
		$(RM) $(OBJ)

fclean:			clean
		$(RM) $(NAME)

re:				fclean all

.PHONY: all, clean, fclean, re