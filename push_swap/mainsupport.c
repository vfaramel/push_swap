/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainsupport.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 23:03:11 by vfaramel          #+#    #+#             */
/*   Updated: 2023/04/18 03:11:54 by vfaramel         ###   ########.fr       */
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
	if ((s[i] == '-') | (s[i] == '+'))
	{
		i++;
		if (!s[i])
			return (1);
	}
	while (s[i])
	{
		if (!(ft_isdigit(s[i])))
			return (0);
		i++;
	}
	return (1);
}
