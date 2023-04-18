/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacenumbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 06:39:02 by vfaramel          #+#    #+#             */
/*   Updated: 2023/04/18 03:17:23 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	replacenumbers(t_gen *gen)
{
	int	i;
	int	x;
	int	count;

	i = 0;
	if (!gen->base)
		quit(gen);
	gen->a = malloc(gen->msize * sizeof(int));
	while (i < gen->msize)
	{
		count = 1;
		x = 0;
		while (x < gen->msize)
		{
			if (gen->base[x] < gen->base[i])
				count++;
			if (gen->base[x] == gen->base[i] && x != i)
				quit(gen);
			x++;
		}
		gen->a[i++] = count;
	}
	gen->step++;
	return ;
}
