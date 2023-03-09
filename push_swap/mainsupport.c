/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainsupport.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 23:03:11 by vfaramel          #+#    #+#             */
/*   Updated: 2023/03/10 00:25:34 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	*argc2(char *argv, t_gen *gen)
{
	char	**arr;
	int		size;
	int		i;
	int		*base;

	size = 0;
	i = 0;
	arr = ft_split(argv, ' ');
	if (!arr)
		return (0);
	while (arr[size] != 0)
		size++;
	base = ft_calloc((size), sizeof(int));
	while (i < size)
	{
		if (!ft_isnumeric(arr[i]) || toobig(arr[i]))
			return (0);
		base[size - 1 - i] = ft_atoi(arr[i]);
		free(arr[i]);
		i++;
	}
	gen->msize = size;
	free(arr);
	return (base);
}

int	*argcmore(int argc, char **argv, t_gen *gen)
{
	int	i;
	int	*base;

	i = -1;
	gen->msize = argc - 1;
	base = ft_calloc((gen->msize), sizeof(int));
	while (++i < gen->msize)
	{
		if (!ft_isnumeric(argv[i + 1]) || toobig(argv[i + 1]))
			return (0);
		base[argc - 2 - i] = ft_atoi(argv[i + 1]);
	}
	return (base);
}
