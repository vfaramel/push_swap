/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacenumbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 06:39:02 by vfaramel          #+#    #+#             */
/*   Updated: 2023/04/13 01:28:14 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*replacenumbers(t_gen *gen)
{
	int	i;
	int	x;
	int	count;
	int	*a1;

	i = 0;
	if (!gen->base)
		return (0);
	a1 = malloc(gen->msize * sizeof(int));
	while (i < gen->msize)
	{
		count = 1;
		x = 0;
		while (x < gen->msize)
		{
			if (gen->base[x] < gen->base[i])
				count++;
			if (gen->base[x] == gen->base[i] && x != i)
				return (0);
			x++;
		}
		a1[i++] = count;
	}
	gen->step++;
	return (a1);
}
