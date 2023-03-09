# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 14:18:00 by vfaramel          #+#    #+#              #
#    Updated: 2023/03/10 00:09:56 by vfaramel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= checks.c ft_rotate.c ft_rrotate.c main.c ft_swap_push.c push_swap.c putplace.c quickpath.c replacenumbers.c mainsupport.c
SRCB	= checks.c ft_rotate_checker.c ft_rrotate_checker.c maingnl.c ft_swap_push_checker.c push_swap.c putplace.c quickpath.c replacenumbers.c get_next_line_bonus.c get_next_line_utils_bonus.c mainsupport.c

OBJS	=	$(SRCS:.c=.o)
OBJB	=	$(SRCB:.c=.o)
CFLAGS	=	-Wall -Wextra -Werror -I.
CC		= gcc
NAME	= push_swap
all		: $(NAME)
$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) libft.a -o $(NAME)
bonus	: $(OBJB)
	$(CC) $(CFLAGS) $(OBJB) libft.a -o checker
clean	:
	rm -f $(OBJS) $(OBJB)
fclean	: clean
	rm -f $(NAME) checker
re	: fclean all
