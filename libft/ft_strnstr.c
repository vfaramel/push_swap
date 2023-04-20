/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvega-ja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:17:04 by vvega-ja          #+#    #+#             */
/*   Updated: 2023/03/22 14:42:44 by vvega-ja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s2[i])
	{
		if ((s1[i] != s2[i]) || i >= n)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strnstr(const char *big, const char *lil, size_t len)
{
	size_t	i;

	i = 0;
	if (lil[0] == 0)
		return ((char *)big);
	while (i < len && big[i])
	{
		if (big[i] == lil[0] && find(big + i + 1, lil + 1, len - i - 1))
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

/*int main(void)
{
	const char *bigstr = "";
    const char *littlestr = "";
    
	char *ptr;
	ptr = strnstr(bigstr, littlestr, 4);
	printf("bigstr: %s\nlittlestr: %s\n", bigstr, littlestr);

	return (0);
}*/
