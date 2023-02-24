/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacenumbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 06:39:02 by vfaramel          #+#    #+#             */
/*   Updated: 2023/02/16 08:49:07 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*replacenumbers(int	*a, int size)
{
	int	i;
	int	x;
	int	count;
	int	*a1;

	i = 0;
	a1 = malloc(size * sizeof(int));
	while (i < size)
	{
		count = 1;
		x = 0;
		while (x < size)
		{
			if (a[x] < a[i])
				count++;
			if (a[x] == a[i] && x != i)
				return (0);
			x++;
		}
		a1[i++] = count;
	}
	return (a1);
}
