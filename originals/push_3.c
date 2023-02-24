/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 03:06:21 by vfaramel          #+#    #+#             */
/*   Updated: 2023/02/24 18:07:45 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	runwind(int *a, int *asize, int *b, int *bsize)
{
	int	msize;
	int	x;

	x = 0;
	msize = *asize + *bsize;
	while (*asize > 1)
	{
		if (*asize == 3)
		{
			if (msize == a[1])
				x += ft_rrotate(a, *asize);
			else if (msize == a[2])
				x += ft_rotate(a, *asize);
			if (a[1] < a[2])
				x += ft_swap(a, *asize);
			prova(a, b, msize, x);
		}
		while (msize - a[*asize - 1] < a[*asize - 1] - *bsize - 1)
		{
			x += ft_rotate(a, *asize);
			prova(a, b, msize, x);
		}
		if (a[*asize - 1] > a[*asize - 2] && a[*asize - 1] < a[*asize - 3])
			x += ft_swap(a, *asize);
		if (correct_order(a, *asize))
			break ;
		x += push(a, (*asize)--, b, (*bsize)++);
		if (b[*bsize - 1] < *bsize - b[*bsize - 1])
			x += ft_rotate(b, *bsize);
		prova(a, b, msize, x);
	}
	return (x);
}

int	ft_rewind(int *a, int *asize, int *b, int *bsize)
{
	int	msize;
	int	x;

	x = 0;
	msize = *asize + *bsize;
	if (*bsize == 0)
		return (x);
	while (b[*bsize - 1] < *b)
		x += ft_rrotate(b, *bsize);
	x += push(b, (*bsize)--, a, (*asize)++);
//	prova(a, b, msize, x);
	if (*asize > 2)
	{
		if (a[*asize - 1] > a[*asize - 2] && a[*asize - 1] > *a)
		{
			if (!(a[*asize - 3] > a[*asize - 2] && a[*asize - 3] < a[*asize - 1]))
				x += ft_swap(a, *asize);
			else if (*a < a[*asize - 2])
				x += ft_rotate(a, *asize);
		}
		else if (a[*asize - 1] < a[*asize - 2] && a[*asize - 1] < *a)
		{
			if (*a < a[*asize - 2])
				x += ft_rotate(a, *asize);
		}
		else if (a[*asize - 1] > a[*asize - 2] && a[*asize - 1] < *a)
		{
			if (!(a[*asize - 3] > a[*asize - 2] && a[*asize - 3] < a[*asize - 1]))
				x += ft_swap(a, *asize);
			else
				x += ft_rotate(a, *asize);
		}
	//	prova(a, b, msize, x);
	}
	return (x);
}

int	unwind(int *a, int *asize, int *b, int *bsize)
{
	int	msize;
	int	x;

	x = 0;
	msize = *asize + *bsize;
	while (a[*asize - 1] > *a)
		x += ft_rrotate(a, *asize);
	x += push(a, (*asize)--, b, (*bsize)++);
	//prova(a, b, msize, x);
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
	}
	return (x);
}

void	push_swap(int *a, int *b, int msize)
{
	int		bsize;
	int		asize;
	int		x;

	x = 0;
	asize = msize;
	bsize = 0;
	x += runwind(a, &asize, b, &bsize);
	prova(a, b, msize, x);
	while (!correct_order(a, msize))
	{
		while (!correct_order(a, asize))
		{
			 x += unwind(a, &asize, b, &bsize);
			// prova(a, b, msize, x);
		}
		prova(a, b, msize, x);
		while (!rcorrect_order(b, bsize))
		{
			x += ft_rewind(a, &asize, b, &bsize);
			//prova(a, b, msize, x);
		}
		if (correct_order(a, asize) && rcorrect_order(b, bsize))
		{
			while (bsize != 0)
				x += push(b, bsize--, a, asize++);
		}
		prova(a, b, msize, x);
	}
	prova(a, b, msize, x);
}
