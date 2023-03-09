/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:59:50 by vfaramel          #+#    #+#             */
/*   Updated: 2023/03/10 00:08:57 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rrotatea(t_gen *gen)
{
	int	temp;
	int	i;
	int	size;

	i = -1;
	size = gen->asize - 1;
	temp = gen->a[0];
	while (i++ < size)
		gen->a[i] = gen->a[i + 1];
	gen->a[size] = temp;
	return (1);
}

int	ft_rrotateb(t_gen *gen)
{
	int	temp;
	int	i;
	int	size;

	i = -1;
	size = gen->bsize - 1;
	temp = gen->b[0];
	while (i++ < size)
		gen->b[i] = gen->b[i + 1];
	gen->b[size] = temp;
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
	return (1);
}
