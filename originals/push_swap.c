/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 09:59:22 by vfaramel          #+#    #+#             */
/*   Updated: 2023/02/23 02:29:38 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sunwind(int *a, int *asize, int *b, int *bsize)
{
	int	msize;
	int	x;

	x = 0;
	msize = *asize + *bsize;
	if (!(*bsize > 1 && b[*bsize - 1] < b[*bsize - 2]))
		x += ft_swap(a, *asize);
	else if (!(*asize > 1 && a[*asize - 1] > a[*asize - 2]))
		x += ft_swap(b, *bsize);
	else
		x += ft_biswap(a, *asize, b, *bsize);
	prova(a, b, msize, x);
	x += runwind(a, asize, b, bsize);
	return (x);
}

int	runwind(int *a, int *asize, int *b, int *bsize)
{
	int	msize;
	int	x;

	x = 0;
	msize = *asize + *bsize;
	while ((msize - a[*asize - 1] < a[*asize - 1] - *bsize - 1)
		|| (*bsize > 0 && b[*bsize - 1] < msize - b[*bsize - 1] - *asize))
	{
		if (!(*bsize > 0 && b[*bsize - 1] < msize - b[*bsize - 1] - *asize))
			(x += ft_rotate(a, *asize));
		else if (!(msize - a[*asize - 1] < a[*asize - 1] - *bsize - 1))
			(x += ft_rotate(b, *bsize));
		else
			x += ft_birotate(a, *asize, b, *bsize);
		prova(a, b, msize, x);
	}
	if ((*asize > 1 && a[*asize - 1] > a[*asize - 2])
		|| (*bsize > 1 && b[*bsize - 1] < b[*bsize - 2]))
		x += sunwind(a, asize, b, bsize);
	return (x);
}

int	unwind(int *a, int *asize, int *b, int *bsize)
{
	int	msize;
	int	x;

	x = 0;
	msize = *asize + *bsize;
	while (*asize > 1)
	{
		x += runwind(a, asize, b, bsize);
		if (correct_order(a, *asize))
			break ;
		x += push(a, (*asize)--, b, (*bsize)++);
		prova(a, b, msize, x);
		// if (*bsize < 2)
		// 	x += push(a, (*asize)--, b, (*bsize)++);
	//	prova(a, b, msize, x);
	}
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
	while (!correct_order(a, msize))
	{
		x += unwind(a, &asize, b, &bsize);
		while (bsize > 1)
		{
			while (b[bsize - 1] < msize - b[bsize - 1] - asize)
			{
				if (asize > 0 && (msize - a[asize - 1]
						< a[asize - 1] - bsize - 1))
					x += ft_birotate(a, asize, b, bsize);
				else
					x += ft_rotate(b, bsize);
				prova(a, b, msize, x);
			}
			if (b[bsize - 1] < b[bsize - 2])
			{
				if (asize > 1 && a[asize - 1] > a[asize - 2])
					x += ft_biswap(a, asize, b, bsize);
				x += ft_swap(b, bsize);
				prova(a, b, msize, x);
			}
			if (rcorrect_order(b, bsize))
				break ;
			x += push(b, bsize--, a, asize++);
			prova(a, b, msize, x);
		}
		if (correct_order(a, asize) && rcorrect_order(b, bsize))
			break ;
	//	x += push(b, bsize--, a, asize++);
		prova(a, b, msize, x);
		//break ;
	}
	while (bsize > 0)
		x += push(b, bsize--, a, asize++);
	prova(a, b, msize, x);
}
