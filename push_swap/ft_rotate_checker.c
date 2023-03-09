/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:29:25 by vfaramel          #+#    #+#             */
/*   Updated: 2023/03/10 00:08:47 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotatea(t_gen *gen)
{
	int	temp;
	int	size;

	size = gen->asize - 1;
	temp = gen->a[size];
	while (size-- != 0)
		gen->a[size + 1] = gen->a[size];
	gen->a[0] = temp;
	return (1);
}

int	ft_rotateb(t_gen *gen)
{
	int	temp;
	int	size;

	size = gen->bsize - 1;
	temp = gen->b[size];
	while (size-- != 0)
		gen->b[size + 1] = gen->b[size];
	gen->b[0] = temp;
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
	return (1);
}
