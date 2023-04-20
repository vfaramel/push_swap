/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvega-ja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:40:02 by vvega-ja          #+#    #+#             */
/*   Updated: 2023/03/29 16:35:39 by vvega-ja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	return (0);
}
/*int main()
{
	char c;
    c = 'Q';
    printf("\nCarattare maiuscolo: %d", ft_isalpha(c));

    c = 'q';
    printf("\nCarattere minuscolo: %d", ft_isalpha(c));

    c ='+';
    printf("\nNon è un carattere alfabetico: %d", ft_isalpha(c));

    return 0;
}*/
