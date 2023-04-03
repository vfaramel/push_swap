/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainsupport.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 23:03:11 by vfaramel          #+#    #+#             */
/*   Updated: 2023/03/30 03:05:37 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen1(char *c)

{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

int	toobig(char *str)
{
	int		i;
	long	tot;
	int		n;

	tot = 0;
	i = 0;
	n = 1;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			n *= -1;
		i++;
	}
	while (48 <= str[i] && str[i] <= 57)
	{
		tot = str[i] - 48 + (tot * 10);
		i++;
	}
	if (tot > INT_MAX || tot < INT_MIN)
		return (1);
	return (0);
}

int	ft_isnumeric(char *s)

{
	int	i;

	i = 0;
	if (s[i] == '-')
		i++;
	while (s[i])
	{
		if (!(ft_isdigit(s[i])))
			return (0);
		i++;
	}
	return (1);
}

void	argc2(char *argv, t_gen *gen)
{
	int		size;
	int		i;

	size = 0;
	i = 0;
	gen->c_base = ft_split(argv, ' ');
	if (!gen->c_base)
		return ;
	while (gen->c_base[size] != 0)
		size++;
	gen->msize = size;
	if (size == 0)
		return ;
	gen->base = ft_calloc((size), sizeof(int));
	if (!gen->base)
		return ;
	while (i < size)
	{
		if (!ft_isnumeric(gen->c_base[i]) || toobig(gen->c_base[i])
			|| ft_strlen1(gen->c_base[i]) == 0)
			return ;
		gen->base[size - 1 - i] = ft_atoi(gen->c_base[i]);
		i++;
	}
}

void	argcmore(int argc, char **argv, t_gen *gen)
{
	int	i;

	i = -1;
	gen->msize = argc - 1;
	gen->base = ft_calloc((gen->msize), sizeof(int));
	while (++i < gen->msize)
	{
		if (!ft_isnumeric(argv[i + 1]) || toobig(argv[i + 1])
			|| ft_strlen1(argv[i + 1]) == 0)
			return ;
		gen->base[argc - 2 - i] = ft_atoi(argv[i + 1]);
	}
}
