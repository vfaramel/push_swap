/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 03:22:58 by vfaramel          #+#    #+#             */
/*   Updated: 2023/04/03 05:15:59 by vfaramel         ###   ########.fr       */
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
	free(gen->b);
	free(gen->a);
}

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
	gen.a = replacenumbers(gen.base, gen.msize);
	gen.b = ft_calloc((gen.msize), sizeof(int));
	if (gen.a == 0)
	{
		write(1, "Error\n", 6);
		quit(&gen, argc);
		return (0);
	}
	push_swap(&gen);
	quit(&gen, argc);
	return (0);
}
