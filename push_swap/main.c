/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 03:22:58 by vfaramel          #+#    #+#             */
/*   Updated: 2023/02/24 17:38:14 by vfaramel         ###   ########.fr       */
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
	gen.b = ft_calloc((argc - 1), sizeof(int));
	base = ft_calloc((argc - 1), sizeof(int));
	while (++i < argc - 1)
	{
		base[argc - 2 - i] = atoi(argv[i + 1]);
	}
	i = 0;
	gen.a = replacenumbers(base, gen.msize);
	push_swap(&gen);
	return (0);
}
