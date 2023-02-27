/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 03:22:58 by vfaramel          #+#    #+#             */
/*   Updated: 2023/02/27 01:17:37 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*base;
	int		i;
	t_gen	gen;

	i = -1;
	gen.msize = argc - 1;
	gen.x = 0;
	gen.b = calloc((argc - 1), sizeof(int));
	base = calloc((argc - 1), sizeof(int));
	while (++i < argc - 1)
	{
		base[argc - 2 - i] = atoi(argv[i + 1]);
	}
	i = 0;
	gen.a = replacenumbers(base, gen.msize);
	if (gen.a == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	push_swap(&gen);
	return (0);
}
