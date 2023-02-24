/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:30:48 by vfaramel          #+#    #+#             */
/*   Updated: 2023/02/17 15:05:18 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prova(int *a, int *b, int msize, int x)
{
	int	i;

	i = 0;
	while (i < msize)
		printf("%d ", a[i++]);
	printf("\n");
	i = 0;
	while (i < msize)
		printf("%d ", b[i++]);
	printf("\n		%d\n", x);
}

int	correct_order(int *a, int msize)
{
	int	i;

	i = 0;
	if (a[msize - 1] == 0)
		return (0);
	while (i < msize - 1)
	{
		if (a[i] != a[i + 1] + 1)
			return (0);
		i++;
	}
	return (1);
}

int	rcorrect_order(int *a, int msize)
{
	int	i;

	i = 0;
	if (a[msize - 1] == 0)
		return (0);
	while (i < msize - 1)
	{
		if (a[i] + 1 != a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
