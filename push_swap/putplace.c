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
	gen->x += push(gen->b, (gen->bsize)--, gen->a, (gen->asize)++);
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
	gen->x += push(gen->b, (gen->bsize)--, gen->a, (gen->asize)++);
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
	gen->x += push(gen->b, (gen->bsize)--, gen->a, (gen->asize)++);
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
	gen->x += push(gen->b, (gen->bsize)--, gen->a, (gen->asize)++);
}

void	putplace(t_gen *gen, int i)
{
	int n;
//controlla ordine per favore, da lucido
	n = findspace(gen->a, gen->asize, gen->b[i - 1]);
	//printf("\n%d %d %d %d\n", gen->bsize - i, i, gen->asize - n, n);
		printf("\n%d %d\n", gen->b[i - 1], gen->a[n - 1]);

	if (gen->bsize - i > i && gen->asize - n > n)
		backw(gen, i, n);
	else if (gen->bsize - i < i && gen->asize - n < n)
		forw(gen, gen->bsize - i, gen->asize - n);
	else if (gen->bsize - i < i && gen->asize - n > n)
	{
		if (gen->asize - n > n + gen->bsize - i && i > n + gen->bsize - i)
			splitb(gen, gen->bsize - i, n);
		else if (i > gen->asize - n)
			forw(gen, gen->bsize - i, gen->asize - n);
		else
			backw(gen, i, n);
	}
	else if (gen->bsize - i > i && gen->asize - n < n)
	{
		if (gen->bsize - i > i + gen->asize - n && n > i + gen->asize - n)
			splita(gen, i, gen->asize - n);
		else if (n > gen->bsize - i)
			forw(gen, gen->bsize - i, gen->asize - n);
		else
			backw(gen, i, n);
	}
	else 
		gen->x += push(gen->b, (gen->bsize)--, gen->a, (gen->asize)++);
}

