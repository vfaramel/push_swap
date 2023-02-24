/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:29:25 by vfaramel          #+#    #+#             */
/*   Updated: 2023/02/17 17:02:59 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotate(int *a, int size)
{
	int	temp;

	size--;
	temp = a[size];
	while (size--)
		a[size + 1] = a[size];
	a[0] = temp;
	return (1);
}

int	ft_birotate(int *a, int asize, int *b, int bsize)
{
	return (ft_rotate(a, asize) + ft_rotate(b, bsize) - 1);
}

int	ft_rrotate(int *a, int size)
{
	int	temp;
	int	i;

	i = -1;
	size--;
	temp = a[0];
	while (i++ < size)
		a[i] = a[i + 1];
	a[size] = temp;
	return (1);
}

int	ft_birrotate(int *a, int asize, int *b, int bsize)
{
	return (ft_rrotate(a, asize) + ft_rrotate(b, bsize) - 1);
}
