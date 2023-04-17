/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makebase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:34:46 by vfaramel          #+#    #+#             */
/*   Updated: 2023/04/17 20:53:35 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_base(t_gen *gen)
{
	int	i;
	int	n;
	int	z;

	i = 0;
	n = 0;
	z = 0;
	while (i < argc - 1)
	{
		while (gen->c_base[i][n] != 0)
		{
			if (!ft_isnumeric(gen->c_base[i][n]) || toobig(gen->c_base[i][n])
			|| ft_strlen1(gen->c_base[i][n]) == 0)
				quit(gen, 2);
			gen->base[gen->msize - 1 - z++] = ft_atoi(gen->c_base[i][n]);
			n++;
		}
		i++;
	}
}

void	original_stack(char *argv, t_gen *gen, int argc)
{
	char	***split_source;
	int		i;
	int		n;

	i = 0;
	gen->c_base = malloc((argc - 1) * sizeof(**char));
	if (!gen->c_base)
		quit(gen);
	while (++i < argc)
	{
		n = 0;
		gen->c_base[i - 1] = ft_split(argv[i], ' ');
		while (gen->c_base[i - 1][n++] != 0)
			gen->msize++;
	}
	gen->base = ft_calloc((gen->msize), sizeof(int));
	if (!gen->base)
		return ;
	make_base(gen);
}
