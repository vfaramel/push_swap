/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putplace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:44:31 by vfaramel          #+#    #+#             */
/*   Updated: 2023/02/25 00:20:57 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void forw(t_gen *gen, int i, int n)
{
	while (i != 0 && n != 0)
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
	while (i != 0)
	{
		gen->x += ft_rotate(gen->b, gen->bsize);
		i--;
	}
}

void	backw(t_gen *gen, int i, int n)
{
	while (i != 0 && n != 0)
	{
		gen->x += ft_birrotate(gen);
		i--;
		n--;
	}
	while (n != 0)
	{
		gen->x += ft_rrotate(gen->a, gen->asize);
		n--;
	}
	while (i != 0)
	{
		gen->x += ft_rrotate(gen->b, gen->bsize);
		i--;
	}
}

void	splitb(t_gen *gen, int i, int n)
{
	while (i != 0)
	{
		gen->x += ft_rotate(gen->b, gen->bsize);
		i--;
	}
	while (n != 0)
	{
		gen->x += ft_rrotate(gen->a, gen->asize);
		n--;
	}
}

void	splita(t_gen *gen, int i, int n)
{
	while (i != 0)
	{
		gen->x += ft_rrotate(gen->b, gen->bsize);
		i--;
	}
	while (n != 0)
	{
		gen->x += ft_rotate(gen->a, gen->asize);
		n--;
	}
}

int	putplace(t_gen *gen, int i, int n)
{
	int	n;
//controlla ordine per favore, da lucido
	n = findspace(gen->a, gen->asize, gen->b[i]);
	if (gen->bsize - i > i && gen->asize - n > n)
		backw(gen, i, n);
	else if (gen->bsize - i < i && gen->asize - n < n)
		forw(gen, gen->bsize - i, gen->asize - n);
	else if (gen->bsize - i < i && gen->asize - n > n)
	{
		if (gen->asize - n > n + gen->bsize - i && i > n + gen->bsize - i)
			slpitb(gen, gen->bsize - i, n);
		else if (i > gen->asize - n)
			forw(gen->bsize - i, gen->asize - n);
		else
			backw(i, n);
	}
	else if (gen->bsize - i > i && gen->asize - n < n)
	{
		if (gen->bsize - i > i + gen->asize - n && n > i + gen->asize - n)
			slpita(gen, gen->bsize - i, n);
		else if (n > gen->bsize - i)
			tcount = maxint(*asize - n, *bsize - i);
		else
			tcount = maxint(i, n);
	}
}
