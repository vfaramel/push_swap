/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickpath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:59:43 by vfaramel          #+#    #+#             */
/*   Updated: 2023/02/24 22:05:16 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	maxint(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	findspace(int *a, int asize, int b)
{
	int	n;

	n = 0;
	while (n < asize - 1)
	{
		if (a[n] > b && b > a[n + 1] || (a[n] < a[n + 1] && a[n] > b))
			break ;
		n++;
	}
	return (n + 1);
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
	{
		if (asize - n >= n + bsize - i && i >= n + bsize - i)
			tcount = n + bsize - i;
		else if (i >= asize - n)
			tcount = maxint(asize - n, bsize - i);
		else
			tcount = maxint(i, n);
	}
	if (bsize - i >= i && asize - n <= n)
	{
		if (bsize - i >= i + asize - n && n >= i + asize - n)
			tcount = i + asize - n;
		else if (n >= bsize - i)
			tcount = maxint(asize - n, bsize - i);
		else
			tcount = maxint(i, n);
	}
	return (tcount);
}

void	quickpath(t_gen *gen)
{
	int	count;
	int	d;
	int	n;
	int	tcount;
	int	w;

	count = gen->asize + gen->bsize;
	d = 0;
	w = 0;
	while (d < count && d < gen->bsize / 2)
	{
		n = findspace(gen->a, gen->asize, gen->b[gen->bsize - 1 - d]);
		tcount = tempcount(gen->bsize - d, n, gen->asize, gen->bsize);
		if (tcount < count)
		{
			count = tcount;
			w = gen->bsize - 1 - d;
		}
		// printf("%d b%d a%d\n",tcount, gen->bsize - 1 - d, n);
		n = findspace(gen->a, gen->asize, gen->b[d]);
		tcount = tempcount(d + 1, n, gen->asize, gen->bsize);
		if (tcount < count)
		{
			count = tcount;
			w = d;
		}
		d++;
		// printf("%d b%d a%d\n",tcount, gen->bsize -1 - d, n);
	}
	// printf("\n%d %d\n", count, w);
	putplace(gen, w + 1); /////FILL
	prova(gen);
}
