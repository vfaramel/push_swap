/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 07:35:35 by vfaramel          #+#    #+#             */
/*   Updated: 2023/04/25 03:01:39 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	centera(t_gen *gen)
{
	int	i;

	i = 0;
	while (gen->a[i] != gen->msize)
		i++;
	if (i <= gen->msize / 2)
	{
		while (gen->a[0] != gen->msize)
			gen->x += ft_rrotatea(gen);
	}
	else
	{
		while (gen->a[0] != gen->msize)
			gen->x += ft_rotatea(gen);
	}
}

int	countdiff(t_gen *gen)
{
	int	maj;
	int	min;
	int	i;
	int	x;

	x = 0;
	maj = 0;
	min = 0;
	i = 0;
	while (i < gen->bsize - 1)
	{
		if (gen->b[i] < gen->b[gen->bsize - 1])
			min++;
		if (gen->b[i] > gen->b[gen->bsize - 1])
			maj++;
		i++;
	}
	if (maj > min)
		x += ft_rotateb(gen);
	return (x);
}

int	is_lis(t_gen *gen, int num)
{
	int	i;

	i = 0;
	while (i < gen->len_lis)
	{
		if (gen->lis[i++] == num)
		{
			return (1);
		}
	}
	return (0);

}

void	pushable_nums(int i, t_gen *gen)
{
	if (i%2 == 1)
	{
		if (is_lis(gen, (gen->msize / 2) + 1 + (i / 2)))
		{
			gen->aug++;
			pushable_nums(i + 1, gen);
		}
	}
	else
	{
		if (is_lis(gen, (gen->msize / 2) + 1 - (i / 2)))
		{
			gen->aug++;
			pushable_nums(i + 1, gen);
		}
	}
}

void	runwind(t_gen *gen)
{
	int i;
	int perc;

	i = 1;
	gen->aug = 0;
	perc = gen->msize * (27 - (gen->msize / 100)) / 100;
	if (gen->msize % 5 > 0)
		perc++;
	while (i <= perc + gen->aug)
		pushable_nums(i++ + gen->aug, gen);
	while (gen->asize > 3 && gen->asize > gen->len_lis)
	{
		if (is_lis(gen, gen->a[gen->asize - 1]))
			gen->x += ft_rotatea(gen);
		else
		{
			// if (gen->msize - gen->a[gen->asize - 1] + 1
			// 	< gen->a[gen->asize - 1] - gen->bsize - 1 && gen->asize > gen->len_lis * 2)
			// 	gen->x += ft_rotatea(gen);
			if ((gen->a[gen->asize - 1] <= ((gen->msize / 2) + ((perc + gen->aug + gen->bsize) - ((perc + gen->aug + gen->bsize) / 2)))) &&
				(gen->a[gen->asize - 1] > ((gen->msize / 2) - ((perc + gen->aug + gen->bsize) / 2))))
			{
				gen->x += pushb(gen);
				pushable_nums(perc + gen->aug + gen->bsize, gen);
				gen->x += countdiff(gen);
			}
			else
				gen->x += ft_rotatea(gen);
		}
	}
	if (gen->asize == 3)
	{
		if (gen->a[0] < gen->a[1] && gen->a[1] < gen->a[2])
			gen->x += ft_swapa(gen);
		else if (gen->a[1] < gen->a[2] && gen->a[2] < gen->a[0])
			gen->x += ft_swapa(gen);
		else if (gen->a[2] < gen->a[0] && gen->a[0] < gen->a[1])
			gen->x += ft_swapa(gen);
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
	prova(gen);
}
