/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:29:25 by vfaramel          #+#    #+#             */
/*   Updated: 2023/02/24 22:08:00 by vfaramel         ###   ########.fr       */
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

int	ft_birotate(t_gen *gen)
{
	return (ft_rotate(gen->a, gen->asize) + ft_rotate(gen->b, gen->bsize) - 1);
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

int	ft_birrotate(t_gen *gen)
{
	return (ft_rrotate(gen->a, gen->asize)
		+ ft_rrotate(gen->b, gen->bsize) - 1);
}
