/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 04:21:02 by vfaramel          #+#    #+#             */
/*   Updated: 2023/02/17 17:03:13 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap(int *a, int size)
{
	int	temp;

	size--;
	temp = a[size];
	a[size] = a[size - 1];
	a[size - 1] = temp;
	return (1);
}

int	ft_biswap(int *a, int asize, int *b, int bsize)
{
	return (ft_swap(a, asize) + ft_swap(b, bsize) - 1);
}

int	push(int *a, int asize, int *b, int bsize)
{
	b[bsize] = a[asize - 1];
	a[asize - 1] = 0;
	return (1);
}
