/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 07:35:35 by vfaramel          #+#    #+#             */
/*   Updated: 2023/03/07 22:03:36 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	centera(t_gen *gen)
{
	int	i;

	i = 0;
	while (gen->a[i] != gen->msize)
		i++;
	if (i < gen->msize / 2)
	{
		while (gen->a[0] != gen->msize)
			gen->x += ft_rrotatea(gen->a, gen->asize);
	}
	else
	{
		while (gen->a[0] != gen->msize)
			gen->x += ft_rotatea(gen->a, gen->asize);
	}
}

int	countdiff(int *b, int bsize)
{
	int	maj;
	int	min;
	int	i;
	int	x;

	x = 0;
	maj = 0;
	min = 0;
	i = 0;
	while (i < bsize)
	{
		if (b[i] < b[bsize - 1])
			min++;
		if (b[i] > b[bsize - 1])
			maj++;
		i++;
	}
	if (maj > b[bsize - 1] - min - 1)
		x += ft_rotateb(b, bsize);
	return (x);
}

void	runwind(t_gen *gen)
{
	while (gen->asize > 3)
	{
		while (gen->msize - gen->a[gen->asize - 1]
			< gen->a[gen->asize - 1] - gen->bsize - 1)
			gen->x += ft_rotatea(gen->a, gen->asize);
		gen->x += pushb(gen->a, (gen->asize)--, gen->b, (gen->bsize)++);
		gen->x += countdiff(gen->b, gen->bsize);
	}
	if (gen->asize == 3)
	{
		if (gen->a[1] > gen->a[0] && gen->a[1] > gen->a[2])
			gen->x += ft_rrotatea(gen->a, gen->asize);
		else if (gen->a[2] > gen->a[0] && gen->a[2] > gen->a[1])
			gen->x += ft_rotatea(gen->a, gen->asize);
		if (gen->a[1] < gen->a[2])
			gen->x += ft_swapa(gen->a, gen->asize);
	}
	else
	{
		if (gen->a[1] > gen->a[0])
			gen->x += ft_swapa(gen->a, gen->asize);
	}
}

void	push_swap(t_gen *gen)
{
	gen->asize = gen->msize;
	gen->bsize = 0;
	runwind(gen);
	while (gen->bsize != 0)
		quickpath(gen);
	centera(gen);
}
