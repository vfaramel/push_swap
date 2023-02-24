/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickpath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:59:43 by vfaramel          #+#    #+#             */
/*   Updated: 2023/02/24 19:26:19 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	putplace(t_gen *gen, int i)
{
	int	x;
	int	n;

	x = 0;
	n = findspace(gen->a, gen->asize, gen->b[i]);
	if (gen->bsize - i > i && gen->asize - n > n)
	{
		if (i <= n)
		{
			while (i != 0)
			{
				x += ft_birotate(gen);
				i--;
				n--;
			}
			while (n != 0)
			{
				x += ft_rotate(gen->a, gen->asize);
				n--;
			}
			
		}
	}
	else if (*bsize - i < i && *asize - n < n)
	{}
}

int	maxint(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	findspace(int *a, int *asize, int b)
{
	int	n;

	n = 0;
	while (n < *asize - 1)
	{
		if (a[n] > b && > a[n + 1])
			break ;
		n++;
	}
	return (n);
}

int	tempcount(int i, int n, int *asize, int *bsize)
{
	int	tcount;

	if (*bsize - i > i && *asize - n > n || *bsize - i < i && *asize - n < n)
		tcount = maxint(i, n);
	if (*bsize - i < i && *asize - n > n)
	{
		if (*asize - n > n + *bsize - i && i > n + *bsize - i)
			tcount = n + *bsize - i;
		else if (i > *asize - n)
			tcount = maxint(*asize - n, *bsize - i);
		else
			tcount = maxint(i, n);
	}
	if (*bsize - i > i && *asize - n < n)
	{
		if (*bsize - i > i + *asize - n && n > i + *asize - n)
			tcount = i + *asize - n;
		else if (n > *bsize - i)
			tcount = maxint(*asize - n, *bsize - i);
		else
			tcount = maxint(i, n);
	}
	return (tcount);
}

int	quickpath(int *a, int *asize, int *b, int *bsize)
{
	int	count;
	int	i;
	int	n;
	int	tcount;
	int	w;

	count = *asize + *bsize;
	i = 0;
	while (i < count)
	{
		n = findspace(a, asize, b[*bsize - 1 - i]);
		tcount = tempcount(i, n, *asize, *bsize);
		if (tcount < count)
		{
			count = tcount;
			w = *bsize - 1 - i;
		}
		n = findspace(a, asize, b[i]);
		tcount = tempcount(*bsize - 1 - i, n, *asize, *bsize);
		if (tcount < count)
		{
			count = tcount;
			w = i;
		}
		i++;
	}

	return (w);
}
