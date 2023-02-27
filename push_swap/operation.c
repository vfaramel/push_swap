/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 04:21:02 by vfaramel          #+#    #+#             */
/*   Updated: 2023/02/26 23:12:24 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swapb(int *a, int size)
{
	int	temp;

	size--;
	temp = a[size];
	a[size] = a[size - 1];
	a[size - 1] = temp;
	write(1, "sb\n", 3);
	return (1);
}

int	ft_biswap(int *a, int asize, int *b, int bsize)
{
	write(1, "ss\n", 3);
	return (ft_swapa(a, asize) + ft_swapb(b, bsize) - 1);
}

int	pusha(int *a, int asize, int *b, int bsize)
{
	b[bsize] = a[asize - 1];
	a[asize - 1] = 0;
	write(1, "pa\n", 3);
	return (1);
}

int	ft_rotateb(int *a, int size)
{
	int	temp;

	size--;
	temp = a[size];
	while (size-- != 0)
		a[size + 1] = a[size];
	a[0] = temp;
	write(1, "rb\n", 3);
	return (1);
}

int	ft_swapa(int *a, int size)
{
	int	temp;

	size--;
	temp = a[size];
	a[size] = a[size - 1];
	a[size - 1] = temp;
	write(1, "sa\n", 3);
	return (1);
}
