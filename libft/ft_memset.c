/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvega-ja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:02:36 by vvega-ja          #+#    #+#             */
/*   Updated: 2023/03/30 12:25:29 by vvega-ja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)dest;
	while (i < n)
		ptr[i++] = (unsigned char)c;
	return (dest);
}
/*int	 main()
{
	char dest[] = ("This is string.h library function");
	puts(dest);
	
	memset(dest,'A', 7);
	puts(dest);
	
	return(0);
}*/
