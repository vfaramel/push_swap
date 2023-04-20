/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvega-ja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:29:30 by vvega-ja          #+#    #+#             */
/*   Updated: 2023/03/30 12:23:04 by vvega-ja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	if (dest == src)
		return (dest);
	if (s < d)
	{
		while (n--)
			*(d + n) = *(s + n);
		return (dest);
	}
	while (n--)
		*d++ = *s++;
	return (dest);
}

/*int main ()
{
   char dest[] = "vecchia stringa";
   const char src[]  = "nuova stringa";

   printf("Prima \n\tdest = %s, src = %s\n", dest, src);
   memmove(dest, src, 9);
   printf("Dopo \n\tdest = %s, src = %s\n", dest, src);

   return(0);
}*/
