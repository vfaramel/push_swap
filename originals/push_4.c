/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 07:35:35 by vfaramel          #+#    #+#             */
/*   Updated: 2023/02/24 17:15:53 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	countdiff(int *b, int *bsize)
{
	int	maj;
	int	min;
	int	i;
	int	x;

	x = 0;
	maj = 0;
	min = 0;
	i = 0;
	while(i < *bsize)
	{
		if (b[i] < b[*bsize - 1])
			min++;
		if (b[i] > b[*bsize - 1])
			maj++;
		i++;
	}
	if (maj > b[*bsize - 1] - min - 1)
		x += ft_rotate(b, *bsize);
	return (x);
}

int	ft_search(int *a, int *asize, int *b, int *bsize)
{
	int	i;
	int	x;
	int msize;

	msize = *asize + *bsize;
	i = 0;
	x = 0;
	while (*bsize != b[i])
		i++;
	i++;
	if (i < *bsize - i)
	{
		while (*bsize != b[*bsize - 1])
		{
			x += ft_rrotate(b, *bsize);
		}
	}
	else
	{
		while (*bsize != b[*bsize - 1])
		{
			x += ft_rotate(b, *bsize);
		}
	}
	x += push(b, (*bsize)--, a, (*asize)++);
	return (x);
}

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
			if (a[1] > a[0] && a[0] > a[2])
				x += ft_rrotate(a, *asize);
			else if (a[2] > a[0] && a[2] > a[1])
				x += ft_rotate(a, *asize);
			if (a[1] < a[2])
				x += ft_swap(a, *asize);
			break ;
			//prova(a, b, msize, x);
		}
		while (msize - a[*asize - 1] < a[*asize - 1] - *bsize - 1)
		{
			x += ft_rotate(a, *asize);
		//	prova(a, b, msize, x);
		}
		// if (a[*asize - 1] > a[*asize - 2] && a[*asize - 1] < a[*asize - 3])
		// 	x += ft_swap(a, *asize);
		if (correct_order(a, *asize))
			break ;
		x += push(a, (*asize)--, b, (*bsize)++);
		// if (b[*bsize - 1] < *bsize - b[*bsize - 1])
		// 	x += ft_rotate(b, *bsize);
		x += countdiff(b, bsize);
		prova(a, b, msize, x);
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
		x += ft_search(a, &asize, b, &bsize);
		prova(a, b, msize, x);
	}
}
