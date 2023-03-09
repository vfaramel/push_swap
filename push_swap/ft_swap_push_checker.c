/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_push_checker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 04:21:02 by vfaramel          #+#    #+#             */
/*   Updated: 2023/03/10 00:09:13 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swapa(t_gen *gen)
{
	int	temp;
	int	size;

	size = gen->asize - 1;
	temp = gen->a[size];
	gen->a[size] = gen->a[size - 1];
	gen->a[size - 1] = temp;
	return (1);
}

int	ft_swapb(t_gen *gen)
{
	int	temp;
	int	size;

	size = gen->bsize - 1;
	temp = gen->b[size];
	gen->b[size] = gen->b[size - 1];
	gen->b[size - 1] = temp;
	return (1);
}

int	ft_biswap(t_gen *gen)
{
	return (ft_swapa(gen) + ft_swapb(gen) - 1);
}

int	pusha(t_gen *gen)
{
	gen->a[gen->asize] = gen->b[gen->bsize - 1];
	gen->b[gen->bsize - 1] = 0;
	gen->bsize--;
	gen->asize++;
	return (1);
}

int	pushb(t_gen *gen)
{
	gen->b[gen->bsize] = gen->a[gen->asize - 1];
	gen->a[gen->asize - 1] = 0;
	gen->asize--;
	gen->bsize++;
	return (1);
}
