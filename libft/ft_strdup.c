/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvega-ja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:53:03 by vvega-ja          #+#    #+#             */
/*   Updated: 2023/03/30 14:09:29 by vvega-ja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!(new))
		return (NULL);
	while (*str)
		new[i++] = *str++;
	new[i] = '\0';
	return (new);
}

/*int main(int ac, char **av)
{
	char *mio;
	char *loro;

	if (ac == 2)
	{
		mio = ft_strdup(av[1]);
		loro = strdup(av[1]);
		printf("%s\n%s\n", mio, loro);
	}
	return 0;
}*/
