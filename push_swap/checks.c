/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:30:48 by vfaramel          #+#    #+#             */
/*   Updated: 2023/04/25 01:21:52 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quit(t_gen *gen)
{
	int	i;
	int	n;

	i = 0;
	free(gen->base);
	while (gen->c_base[i] != 0)
	{
		n = 0;
		while (gen->c_base[i][n] != 0)
			free(gen->c_base[i][n++]);
		free(gen->c_base[i]);
		i++;
	}
	free(gen->c_base);
	if (gen->step > 0)
	{
		free(gen->b);
		free(gen->a);
		free(gen->lis);
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

int	abs_num(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	findspace(int *a, int asize, int b)
{
	int	n;

	n = 0;
	while (n < asize - 1)
	{
		if ((a[n] > b && b > a[n + 1]) || ((a[n] < a[n + 1]) && a[n] > b) || ((a[n] < a[n + 1]) && a[n + 1] < b))
			break ;
		n++;
	}
	return (n + 1);
}
