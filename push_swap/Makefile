# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 14:18:00 by vfaramel          #+#    #+#              #
#    Updated: 2023/04/17 21:08:12 by vfaramel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT	= ../libft/ft_isdigit.c ../libft/ft_atoi.c ../libft/ft_split.c ../libft/ft_calloc.c ../libft/ft_substr.c ../libft/ft_bzero.c \
		../libft/ft_strlen.c ../libft/ft_strdup.c ../libft/ft_memset.c
SRCS	= $(LIBFT) checks.c push_swap.c putplace.c quickpath.c replacenumbers.c mainsupport.c makebase.c
SRCA	= $(SRCS) main.c ft_rotate.c ft_rrotate.c ft_swap_push.c lis.c
SRCB	= $(SRCS) main_checker.c ft_rotate_checker.c ft_rrotate_checker.c ft_swap_push_checker.c \
		../get_next_line/get_next_line_bonus.c ../get_next_line/get_next_line_utils_bonus.c

CFLAGS	=	-Wall -Wextra -Werror -I.
CC		= gcc
NAME	= push_swap
all		: $(SRCS)
	$(CC) $(CFLAGS) $(SRCA) -o $(NAME)
bonus	: $(SRCB)
	$(CC) $(CFLAGS) $(SRCB) -o checker
clean	:
fclean	: clean
	rm -f $(NAME) checker
re	: fclean all
