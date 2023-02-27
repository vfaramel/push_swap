/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:29:25 by vfaramel          #+#    #+#             */
/*   Updated: 2023/02/27 02:02:17 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotatea(int *a, int size)
{
	int	temp;

	size--;
	temp = a[size];
	while (size-- != 0)
		a[size + 1] = a[size];
	a[0] = temp;
	write(1, "ra\n", 3);
	return (1);
}

int	ft_birotate(t_gen *gen)
{
	int	temp;
	int	asize;
	int	bsize;

	asize = gen->asize - 1;
	bsize = gen->bsize - 1;
	temp = gen->a[asize];
	while (asize-- != 0)
		gen->a[asize + 1] = gen->a[asize];
	gen->a[0] = temp;
	temp = gen->b[bsize];
	while (bsize-- != 0)
		gen->b[bsize + 1] = gen->b[bsize];
	gen->b[0] = temp;
	write(1, "rr\n", 3);
	return (1);
}

int	ft_rrotatea(int *a, int size)
{
	int	temp;
	int	i;

	i = -1;
	size--;
	temp = a[0];
	while (i++ < size)
		a[i] = a[i + 1];
	a[size] = temp;
	write(1, "rra\n", 4);
	return (1);
}

int	ft_birrotate(t_gen *gen)
{
	int	temp;
	int	i;
	int	asize;
	int	bsize;

	asize = gen->asize - 1;
	bsize = gen->bsize - 1;
	i = -1;
	temp = gen->a[0];
	while (i++ < asize)
		gen->a[i] = gen->a[i + 1];
	gen->a[asize] = temp;
	i = -1;
	temp = gen->b[0];
	while (i++ < bsize)
		gen->b[i] = gen->b[i + 1];
	gen->b[bsize] = temp;
	write(1, "rrr\n", 4);
	return (1);
}

int	ft_rrotateb(int *a, int size)
{
	int	temp;
	int	i;

	i = -1;
	size--;
	temp = a[0];
	while (i++ < size)
		a[i] = a[i + 1];
	a[size] = temp;
	write(1, "rrb\n", 4);
	return (1);
}
