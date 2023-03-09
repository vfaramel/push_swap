/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putplace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:44:31 by vfaramel          #+#    #+#             */
/*   Updated: 2023/03/09 20:16:17 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	forw(t_gen *gen, int i, int n)
{
	while (i != 0 && n != 0)
	{
		gen->x += ft_birotate(gen);
		i--;
		n--;
	}
	while (n != 0)
	{
		gen->x += ft_rotatea(gen);
		n--;
	}
	while (i != 0)
	{
		gen->x += ft_rotateb(gen);
		i--;
	}
	gen->x += pusha(gen);
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
		gen->x += ft_rrotatea(gen);
		n--;
	}
	while (i != 0)
	{
		gen->x += ft_rrotateb(gen);
		i--;
	}
	gen->x += pusha(gen);
}

void	splitb(t_gen *gen, int i, int n)
{
	while (i != 0)
	{
		gen->x += ft_rotateb(gen);
		i--;
	}
	while (n != 0)
	{
		gen->x += ft_rrotatea(gen);
		n--;
	}
	gen->x += pusha(gen);
}

void	splita(t_gen *gen, int i, int n)
{
	while (i != 0)
	{
		gen->x += ft_rrotateb(gen);
		i--;
	}
	while (n != 0)
	{
		gen->x += ft_rotatea(gen);
		n--;
	}
	gen->x += pusha(gen);
}

void	putplace(t_gen *gen, int i)
{
	int	n;

	n = findspace(gen->a, gen->asize, gen->b[i - 1]);
	if (gen->bsize - i >= i && gen->asize - n >= n)
		backw(gen, i, n);
	else if (gen->bsize - i <= i && gen->asize - n <= n)
		forw(gen, gen->bsize - i, gen->asize - n);
	else if (gen->bsize - i <= i && gen->asize - n >= n)
	{
		if (gen->asize - n >= n + gen->bsize - i && i >= n + gen->bsize - i)
			splitb(gen, gen->bsize - i, n);
		else if (i >= gen->asize - n)
			forw(gen, gen->bsize - i, gen->asize - n);
		else
			backw(gen, i, n);
	}
	else if (gen->bsize - i >= i && gen->asize - n <= n)
	{
		if (gen->bsize - i >= i + gen->asize - n && n >= i + gen->asize - n)
			splita(gen, i, gen->asize - n);
		else if (n >= gen->bsize - i)
			forw(gen, gen->bsize - i, gen->asize - n);
		else
			backw(gen, i, n);
	}
}
