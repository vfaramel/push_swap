/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvega-ja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:02:22 by vvega-ja          #+#    #+#             */
/*   Updated: 2023/03/21 13:11:56 by vvega-ja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

/*int main ()
{
	char c;
	c = 'a';
	printf("Da minuscolo a maiuscolo: %d", ft_toupper(c));

	c = 'A';
	printf("\nIl carattere rimane maiuscolo: %d", ft_toupper(c));
	
	return (0);
}*/
