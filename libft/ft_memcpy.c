/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvega-ja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:53:49 by vvega-ja          #+#    #+#             */
/*   Updated: 2023/03/30 12:18:47 by vvega-ja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
/*int main()
{
	const char src[50] = "ciao come stai";
	char dest[50] = "boooooo";


	printf("Prima memcpy dest = %s\n", dest);
	ft_memcpy(dest, src, strlen(src)+1);
	printf("Dopo memcpy dest = %s\n", dest);

	return (0);
}*/
