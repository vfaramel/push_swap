/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 08:36:40 by vfaramel          #+#    #+#             */
/*   Updated: 2023/04/18 03:36:28 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../get_next_line/get_next_line_bonus.h"
#include "push_swap.h"

int	correct_order(t_gen *gen)
{
	int	i;

	i = 0;
	while (i < gen->msize - 1)
	{
		if (gen->a[i] <= gen->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_strcmpnl(char *s1, char *s2)
{
	int				i;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	i = 0;
	while (p1[i] != '\n' && p2[i] != '\n')
	{
		if (p1[i] != p2[i])
			return (0);
		i++;
	}
	return (1);
}

void	makemove(char *arr, t_gen *gen)
{
	if (ft_strcmpnl(arr, "sa/n"))
		ft_swapa(gen);
	else if (ft_strcmpnl(arr, "sb/n"))
		ft_swapb(gen);
	else if (ft_strcmpnl(arr, "ss/n"))
		ft_biswap(gen);
	else if (ft_strcmpnl(arr, "ra/n"))
		ft_rotatea(gen);
	else if (ft_strcmpnl(arr, "rr/n"))
		ft_birotate(gen);
	else if (ft_strcmpnl(arr, "rra/n"))
		ft_rrotatea(gen);
	else if (ft_strcmpnl(arr, "rb/n"))
		ft_rotateb(gen);
	else if (ft_strcmpnl(arr, "rrb/n"))
		ft_rrotateb(gen);
	else if (ft_strcmpnl(arr, "rrr/n"))
		ft_birrotate(gen);
	else if (ft_strcmpnl(arr, "pa/n"))
		pusha(gen);
	else if (ft_strcmpnl(arr, "pb/n"))
		pushb(gen);
	else
		quit(gen);
}

void	eskere(t_gen *gen)
{
	char	*arr;

	arr = get_next_line(0);
	while (arr)
	{
		free(arr);
		makemove(arr, gen);
		arr = get_next_line(0);
	}
	free(arr);
	if (correct_order(gen))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_gen	gen;

	if (argc == 1)
		return (0);
	gen.step = 0;
	original_stack(argv, &gen, argc);
	gen.b = ft_calloc((gen.msize), sizeof(int));
	replacenumbers(&gen);
	gen.asize = gen.msize;
	gen.bsize = 0;
	eskere(&gen);
	quit(&gen);
	return (0);
}
