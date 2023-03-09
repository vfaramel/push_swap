/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 03:22:58 by vfaramel          #+#    #+#             */
/*   Updated: 2023/03/09 23:02:27 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*base;
	t_gen	gen;

	gen.x = 0;
	if (argc == 1)
		return (0);
	if (argc == 2)
		base = argc2(argv[1], &gen);
	if (argc > 2)
		base = argcmore(argc, argv, &gen);
	gen.a = replacenumbers(base, gen.msize);
	free(base);
	gen.b = ft_calloc((gen.msize), sizeof(int));
	if (gen.a == 0)
	{
		write(1, "Error\n", 6);
		free(gen.b);
		free(gen.a);
		return (0);
	}
	push_swap(&gen);
	free(gen.b);
	free(gen.a);
	return (0);
}
