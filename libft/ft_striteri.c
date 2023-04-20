/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvega-ja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:09:09 by vvega-ja          #+#    #+#             */
/*   Updated: 2023/03/31 15:53:55 by vvega-ja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	if (s && f)
	{
		i = 0;
		while (s[i])
		{
			f(i, &s[i]);
			i++;
		}
	}
}

/*void    f(unsigned int i, char *str)
{
	printf("Indice funzione interna = %d e la stringa %s\n", i, str);
}

int main()
{
	char str[10] = "Ciaooo";
	printf("Risultato: %s\n", str);
	ft_striteri(str, f);
	printf("Risultato: %s\n", str);
	return 0;
}*/
