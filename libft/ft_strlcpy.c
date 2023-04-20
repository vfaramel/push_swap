/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvega-ja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:27:54 by vvega-ja          #+#    #+#             */
/*   Updated: 2023/03/20 17:47:15 by vvega-ja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}

/*int main()
{
    char dst[] = "ciao";
    const char src[] = "come";
	int r;
  
	printf("prima\n\tsrc: %s\n\tdest: %s\n", src, dst);
	
	r = ft_strlcpy(dst, src, 5);
	
	printf("dopo\n\tsrc: %s\n\tdest: %s\n", src, dst);
	return (0);
}*/
