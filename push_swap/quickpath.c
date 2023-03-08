/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickpath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:59:43 by vfaramel          #+#    #+#             */
/*   Updated: 2023/03/07 15:34:50 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	tempcount2(int i, int n, int asize, int bsize)
{
	int	tcount;

	if (asize - n >= n + bsize - i && i >= n + bsize - i)
		tcount = n + bsize - i;
	else if (i >= asize - n)
		tcount = maxint(asize - n, bsize - i);
	else
		tcount = maxint(i, n);
	return (tcount);
}

int	tempcount3(int i, int n, int asize, int bsize)
{
	int	tcount;

	if (bsize - i >= i + asize - n && n >= i + asize - n)
		tcount = i + asize - n;
	else if (n >= bsize - i)
		tcount = maxint(asize - n, bsize - i);
	else
		tcount = maxint(i, n);
	return (tcount);
}

int	tempcount(int i, int n, int asize, int bsize)
{
	int	tcount;

	tcount = 0;
	if (bsize - i >= i && asize - n >= n)
		tcount = maxint(i, n);
	if (i >= bsize - i && n >= asize - n)
		tcount = maxint(bsize - i, asize - n);
	if (i >= bsize - i && asize - n >= n)
		tcount = tempcount2(i, n, asize, bsize);
	if (bsize - i >= i && asize - n <= n)
		tcount = tempcount3(i, n, asize, bsize);
	return (tcount);
}

void	quickpath2(t_gen *gen, int *count, int *w, int d)
{
	int	n;
	int	tcount;

	n = findspace(gen->a, gen->asize, gen->b[gen->bsize - 1 - d]);
	tcount = tempcount(gen->bsize - d, n, gen->asize, gen->bsize);
	if (tcount < *count)
	{
		*count = tcount;
		*w = gen->bsize - 1 - d;
	}
	n = findspace(gen->a, gen->asize, gen->b[d]);
	tcount = tempcount(d + 1, n, gen->asize, gen->bsize);
	if (tcount < *count)
	{
		*count = tcount;
		*w = d;
	}
}

void	quickpath(t_gen *gen)
{
	int	count;
	int	d;
	int	w;

	count = gen->asize + gen->bsize;
	d = 0;
	w = 0;
	while (d < count && d < gen->bsize / 2)
	{
		quickpath2(gen, &count, &w, d);
		d++;
	}
	putplace(gen, w + 1);
}
