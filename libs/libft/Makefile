# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/11 11:26:11 by jjourdan          #+#    #+#              #
#    Updated: 2021/02/05 15:49:40 by jjourdan         ###   ########lyon.fr    #
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

FLAGS		=	-Wall -Wextra -Werror

NAME		=	libft.a

CC			=	gcc

RM			=	rm -f

INC_DIR		=	includes/

INCLUDES	=	libft.h

INC_FULL	=	$(addprefix $(INC_DIR), $(INCLUDES))

SRCS_DIR	=	sources/

SRCS		=	ft_putchar.c \
				ft_strlen.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_bzero.c \
				ft_memset.c \
				ft_memcpy.c \
				ft_memccpy.c \
				ft_memmove.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strncmp.c \
				ft_strlcpy.c \
				ft_atoi.c \
				ft_strdup.c \
				ft_strlcat.c \
				ft_strrchr.c \
				ft_strchr.c \
				ft_strnstr.c \
				ft_calloc.c \
				ft_strcat.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strjoin_free_s1.c \
				ft_strjoin_free_s2.c \
				ft_strtrim.c \
				ft_my_split.c \
				ft_split.c \
				ft_itoa.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_strmapi.c \
				ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c

SRCS_FULL	=	$(addprefix $(SRCS_DIR), $(SRCS))

OBJS		=	$(SRCS_FULL:.c=.o)

all:			$(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $?

%.o: %.c		$(INC_FULL)
		$(CC) -I $(INC_DIR) $(FLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean:			clean
		$(RM) $(NAME)

re:				fclean all

.PHONY: all, clean, fclean, re