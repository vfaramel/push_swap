/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 00:06:59 by vfaramel          #+#    #+#             */
/*   Updated: 2023/02/24 03:51:56 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// unwind prima e poi displace in while

int	runwind(int *a, int *asize, int *b, int *bsize)
{
	int	msize;
	int	x;

	x = 0;
	msize = *asize + *bsize;
	while (msize - a[*asize - 1] < a[*asize - 1] - *bsize - 1)
	{
		x += ft_rotate(a, *asize);
		prova(a, b, msize, x);
	}
	if (a[*asize - 1] > a[*asize - 2] && a[*asize - 1] < a[*asize - 3])
		x += ft_swap(a, *asize);
	while (a[0] < a[*asize - 1])
		x += ft_rrotate(a, *asize);
	return (x);
}

int	unwind(int *a, int *asize, int *b, int *bsize)
{
	int	msize;
	int	x;

	x = 0;
	msize = *asize + *bsize;
	while (*asize > 3)
	{
		x += runwind(a, asize, b, bsize);
		if (correct_order(a, *asize))
			break ;
		x += push(a, (*asize)--, b, (*bsize)++);
		prova(a, b, msize, x);
		if (*bsize > 2)
		{
			if (b[*bsize - 1] < b[*bsize - 2] && b[*bsize - 1] < *b)
			{
				if (!(b[*bsize - 3] < b[*bsize - 2] && b[*bsize - 3] > b[*bsize - 1]))
					x += ft_swap(b, *bsize);
				else if (*b > b[*bsize - 2])
					x += ft_rotate(b, *bsize);
			}
			else if (b[*bsize - 1] > b[*bsize - 2] && b[*bsize - 1] > *b)
			{
				if (*b > b[*bsize - 2])
					x += ft_rotate(b, *bsize);
			}
			else if (b[*bsize - 1] < b[*bsize - 2] && b[*bsize - 1] > *b)
			{
				if (!(b[*bsize - 3] < b[*bsize - 2] && b[*bsize - 3] > b[*bsize - 1]))
					x += ft_swap(b, *bsize);
				else
					x += ft_rotate(b, *bsize);
			}
			prova(a, b, msize, x);
		}
	}
	if (msize == a[1])
		x += ft_rrotate(a, *asize);
	else if (msize == a[2])
		x += ft_rotate(a, *asize);
	if (a[1] < a[2])
		x += ft_swap(a, *asize);
	return (x);
}

void	push_swap(int *a, int *b, int msize)
{
	int		bsize;
	int		asize;
	int		i;
	int		x;

	bsize = 0;
	asize = msize;
	x = 0;
	prova(a, b, msize, x);
	while  (!correct_order(a, msize)) //(x < 100)
	{
		x += unwind(a, &asize, b, &bsize);
		while (bsize > 1)
		{
			if (b[bsize - 1] > b[0])
			{
				if (b[bsize - 1] < b[bsize - 2])
					x += ft_swap(b, bsize);
				x += push(b, bsize--, a, asize++);
			}
			else
			{
				while (b[bsize - 1] < b[0])
					x += ft_rrotate(b, bsize);
				x += push(b, bsize--, a, asize++);
			}
			if (rcorrect_order(b, bsize))
				break ;
			prova(a, b, msize, x);
		}
		if (correct_order(a, asize) && rcorrect_order(b, bsize))
			break ;
		prova(a, b, msize, x);
	}
	while (bsize > 0)
		x += push(b, bsize--, a, asize++);
	prova(a, b, msize, x);
}
