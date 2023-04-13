/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 03:22:58 by vfaramel          #+#    #+#             */
/*   Updated: 2023/04/13 01:40:58 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_gen	gen;

	gen.x = 0;
	if (argc == 1)
		return (0);
	if (argc == 2)
		argc2(argv[1], &gen);
	if (argc > 2)
		argcmore(argc, argv, &gen);
	gen.a = replacenumbers(&gen);
	gen.b = ft_calloc((gen.msize), sizeof(int));
	if (gen.a == 0)
		quit(&gen, argc);
	push_swap(&gen);
	quit(&gen, argc);
	return (0);
}
