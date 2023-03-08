# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 14:18:00 by vfaramel          #+#    #+#              #
#    Updated: 2023/03/07 15:48:54 by vfaramel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= checks.c ft_rotate.c main.c operation.c push_swap.c putplace.c quickpath.c replacenumbers.c

OBJS	=	$(SRCS:.c=.o)
CFLAGS	=	-Wall -Wextra -Werror -I.
CC		= gcc
NAME	= push_swap
all		: $(NAME)
$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) libft.a -o $(NAME)
clean	:
	rm -f $(OBJS)
fclean	: clean
	rm -f $(NAME)
re	: fclean all
