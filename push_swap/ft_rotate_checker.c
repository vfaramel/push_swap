/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:29:25 by vfaramel          #+#    #+#             */
/*   Updated: 2023/03/29 23:48:17 by vfaramel         ###   ########.fr       */
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
	ft_rotatea(gen);
	ft_rotateb(gen);
	return (1);
}
