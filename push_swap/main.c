/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 03:22:58 by vfaramel          #+#    #+#             */
/*   Updated: 2023/04/18 03:34:28 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_gen	gen;

	gen.x = 0;
	gen.step = 0;
	if (argc == 1)
		return (0);
	original_stack(argv, &gen, argc);
	gen.b = ft_calloc((gen.msize), sizeof(int));
	replacenumbers(&gen);
	lis(&gen);
	push_swap(&gen);
	quit(&gen);
	return (0);
}
