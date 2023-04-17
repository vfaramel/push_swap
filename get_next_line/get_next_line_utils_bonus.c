/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 00:00:29 by vfaramel          #+#    #+#             */
/*   Updated: 2023/02/15 23:37:47 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strchr(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s)
	{
		if ('\n' == s[i++])
			return (i);
	}
	return (0);
}

char	*makestr(char *final, int fd)
{
	char	*pbuf;
	ssize_t	x;

	x = BUFFER_SIZE;
	while (!ft_strchr(final) && x == BUFFER_SIZE)
	{
		pbuf = malloc(BUFFER_SIZE + 1);
		x = read(fd, pbuf, BUFFER_SIZE);
		pbuf[x] = '\0';
		final = ft_strjoin(final, pbuf);
	}
	return (final);
}

char	*separate(char *final, char *backup)
{
	int		i;

	i = ft_strchr(final);
	if (i)
	{
		ft_strlcpy(backup, final + i, BUFFER_SIZE);
		final[i] = '\0';
	}
	else
		backup[0] = '\0';
	return (final);
}
