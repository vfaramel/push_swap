/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 07:35:35 by vfaramel          #+#    #+#             */
/*   Updated: 2023/02/24 17:51:16 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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
	while(i < bsize)
	{
		if (b[i] < b[bsize - 1])
			min++;
		if (b[i] > b[bsize - 1])
			maj++;
		i++;
	}
	if (maj > b[bsize - 1] - min - 1)
		x += ft_rotate(b, bsize);
	return (x);
}

// int	ft_search(int *a, int *asize, int *b, int *bsize)
// {
// 	int	i;
// 	int	x;
// 	int msize;

// 	msize = *asize + *bsize;
// 	i = 0;
// 	x = 0;
// 	while (*bsize != b[i])
// 		i++;
// 	i++;
// 	if (i < *bsize - i)
// 	{
// 		while (*bsize != b[*bsize - 1])
// 		{
// 			x += ft_rrotate(b, *bsize);
// 		}
// 	}
// 	else
// 	{
// 		while (*bsize != b[*bsize - 1])
// 		{
// 			x += ft_rotate(b, *bsize);
// 		}
// 	}
// 	x += push(b, (*bsize)--, a, (*asize)++);
// 	return (x);
// }

void	runwind(t_gen *gen)
{
	while (gen->asize > 3)
	{

		while (gen->msize - gen->a[gen->asize - 1] < gen->a[gen->asize - 1] - gen->bsize - 1)
		{
			ft_rotate(gen->a, gen->asize);
			gen->x++;
		}
		// if (a[*asize - 1] > a[*asize - 2] && a[*asize - 1] < a[*asize - 3])
		// 	x += ft_swap(a, *asize);
		// if (correct_order(gen->a, gen->asize))
		// 	break ;
		gen->x +=push(gen->a, (gen->asize)--, gen->b, (gen->bsize)++);
		// if (b[*bsize - 1] < *bsize - b[*bsize - 1])
		// 	x += ft_rotate(b, *bsize);
		gen->x += countdiff(gen->b, gen->bsize);
	}		
	if (gen->asize == 3)
		{
			if (gen->a[1] > gen->a[0] && gen->a[1] > gen->a[2])
				gen->x += ft_rrotate(gen->a, gen->asize);
			else if (gen->a[2] > gen->a[0] && gen->a[2] > gen->a[1])
				gen->x += ft_rotate(gen->a, gen->asize);
			if (gen->a[1] < gen->a[2])
				gen->x += ft_swap(gen->a, gen->asize);
		}
}

void	push_swap(t_gen *gen)
{
	gen->asize = gen->msize;
	gen->bsize = 0;
	runwind(gen);
	prova(gen);
	while(gen->b != 0)
		quickpath(gen);
	prova(gen);
	// while (!correct_order(gen))
	// {
	// 	x += ft_search(gen);
	// 	prova(gen, x);
	// }
	// prova(gen);
}
