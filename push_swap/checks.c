/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:30:48 by vfaramel          #+#    #+#             */
/*   Updated: 2023/04/13 02:16:07 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quit(t_gen *gen, int argc)
{
	int	i;

	i = 0;
	free(gen->base);
	if (argc == 2)
	{
		while (gen->c_base[i] != 0)
		{
			free(gen->c_base[i]);
			i++;
		}
		free(gen->c_base);
	}
	if (gen->step > 0)
	{
		free(gen->b);
		free(gen->a);
	}
	if (gen->step < 2)
		write(1, "Error\n", 6);
	exit (0);
}

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
