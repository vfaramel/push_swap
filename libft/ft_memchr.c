/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvega-ja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:08:37 by vvega-ja          #+#    #+#             */
/*   Updated: 2023/03/29 16:54:04 by vvega-ja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	character;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	character = (unsigned char)c;
	while (i < n)
	{
		if (*str == character)
		{
			return (str);
		}
		str ++;
		i++;
	}
	return (NULL);
}
/*int main()
{
    char str[] = {'a', 'b', 'c', 'd', 'e', 'f'};

    char *pos = ft_memchr(str, 'e', 6);

    if (pos == NULL)
    {
        printf("Character not found\n");
    }
    else
    {
        printf("pos[0] = %c\n", pos[0]);
        printf("pos[1] = %c\n", pos[1]);
    }
    return (0);
}*/
