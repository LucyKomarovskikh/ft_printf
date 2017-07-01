# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/14 19:20:14 by lkomarov          #+#    #+#              #
#    Updated: 2017/03/22 17:33:28 by lkomarov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
OBJ = ft_strdup.o ft_strlen.o ft_strcmp.o ft_strsub.o ft_strnew.o ft_bzero.o ft_printf.o ft_format.o ft_d_num.o ft_ixo.o ft_fill.o ft_pr_ht.o ft_pr_s.o ft_find_nbr.o ft_intcount.o ft_char.o ft_str.o ft_all_toa.o
SRC = ft_strdup.c ft_strlen.c ft_strcmp.c ft_strsub.c ft_strnew.c ft_bzero.c ft_printf.c ft_format.c ft_d_num.c ft_ixo.c ft_fill.c ft_pr_ht.c ft_pr_s.c ft_find_nbr.c ft_intcount.c ft_char.c ft_str.c ft_all_toa.c 

all: $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)

$(OBJ) : $(SRC)
	$(CC) -c -Wall -Wextra -Werror $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

