/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putplace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:44:31 by vfaramel          #+#    #+#             */
/*   Updated: 2023/02/24 19:52:33 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	putplace(t_gen *gen, int i)
{
	int	n;

	n = findspace(gen->a, gen->asize, gen->b[i]);
	if (gen->bsize - i > i && gen->asize - n > n)
	{
		if (i <= n)
		{
			while (i != 0)
			{
				gen->x += ft_birotate(gen);
				i--;
				n--;
			}
			while (n != 0)
			{
				gen->x += ft_rotate(gen->a, gen->asize);
				n--;
			}
		}
	}
	else if (*bsize - i < i && *asize - n < n)
	{}
}

int	case0(t_gen *gen)
{

	if (i <= n)
	{
		while (i != 0)
		{
			gen->x += ft_birotate(gen);
			i--;
			n--;
		}
		while (n != 0)
		{
			gen->x += ft_rotate(gen->a, gen->asize);
			n--;
		}

	}
}
