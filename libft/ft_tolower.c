/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvega-ja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:45:05 by vvega-ja          #+#    #+#             */
/*   Updated: 2023/03/21 13:08:28 by vvega-ja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

/*int main()
{
	char c;
	c = 'A';
	printf("Da maiuscolo a minuscolo: %d", ft_tolower(c));

	c = 'a';
	printf("\nIl carattere rimane minuscolo: %d", ft_tolower(c));
	
	return (0);
}*/
