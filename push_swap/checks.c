/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:30:48 by vfaramel          #+#    #+#             */
/*   Updated: 2023/03/07 15:26:53 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prova(t_gen *gen)
{
	int	i;

	i = 0;
	while (i < gen->msize)
		printf("%d ", gen->a[i++]);
	printf("\n");
	i = 0;
	while (i < gen->msize)
		printf("%d ", gen->b[i++]);
	printf("\n		%d\n", gen->x);
}

int	pushb(int *a, int asize, int *b, int bsize)
{
	b[bsize] = a[asize - 1];
	a[asize - 1] = 0;
	write(1, "pb\n", 3);
	return (1);
}

int	maxint(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	findspace(int *a, int asize, int b)
{
	int	n;

	n = 0;
	while (n < asize - 1)
	{
		if ((a[n] > b && b > a[n + 1]) || ((a[n] < a[n + 1] && a[n] > b)))
			break ;
		n++;
	}
	return (n + 1);
}
