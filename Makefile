# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bferdjan <bferdjan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/05 04:17:21 by bferdjan          #+#    #+#              #
#    Updated: 2024/12/08 03:55:02 by bferdjan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom de la bibliothèque
NAME = libftprintf.a

# Liste des fichiers source
SRC =	srcs/ft_printf.c \
	srcs/conversion_c.c \
	srcs/conversion_d.c \
	srcs/conversion_i.c \
	srcs/conversion_p.c \
	srcs/conversion_s.c \
	srcs/conversion_u.c \
	srcs/conversion_x.c \
	srcs/conversion_X.c \
	srcs/parsing.c \

# Création de la liste des fichiers objet
OBJ = $(SRC:.c=.o)

# Compilateur et options
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Règle principale
all: $(NAME)

# Création de la bibliothèque
$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objet
clean:
	rm -f $(OBJ)

# Nettoyage complet (objets et bibliothèque)
fclean: clean
	rm -f $(NAME)

# Recompilation complète
re: fclean all

