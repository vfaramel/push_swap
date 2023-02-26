/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 03:22:58 by vfaramel          #+#    #+#             */
/*   Updated: 2023/02/24 03:56:55 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	int		*base;
	int		i;
	int		*a;
	int		*b;

	// printf("%d ", argc);
	i = -1;
	b = calloc((argc - 1), sizeof(int));
	base = calloc((argc - 1), sizeof(int));
	while (++i < argc - 1)
	{
		base[argc - 2 - i] = atoi(argv[i + 1]);
	}
	i = 0;
	a = replacenumbers(base, argc - 1);
	push_swap(a, b, argc - 1);
	return (0);
}
