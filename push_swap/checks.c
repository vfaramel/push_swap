/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:30:48 by vfaramel          #+#    #+#             */
/*   Updated: 2023/02/24 17:51:45 by vfaramel         ###   ########.fr       */
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

// int	correct_order(int *a, int msize)
// {
// 	int	i;

// 	i = 0;
// 	if (a[msize - 1] == 0)
// 		return (0);
// 	while (i < msize - 1)
// 	{
// 		if (a[i] != a[i + 1] + 1)
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// int	rcorrect_order(int *a, int msize)
// {
// 	int	i;

// 	i = 0;
// 	if (a[msize - 1] == 0)
// 		return (0);
// 	while (i < msize - 1)
// 	{
// 		if (a[i] + 1 != a[i + 1])
// 			return (0);
// 		i++;
// 	}
// 	return (1);
//}
