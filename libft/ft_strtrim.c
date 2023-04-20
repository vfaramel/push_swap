/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvega-ja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:44:24 by vvega-ja          #+#    #+#             */
/*   Updated: 2023/03/21 12:57:44 by vvega-ja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	charinset(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	u;
	int	len;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	u = 0;
	while (charinset(s1[u], set) == 1)
		u++;
	if (s1[u] == '\0')
		return (ft_substr(s1, u, 1));
	start = u;
	u = 0;
	while (s1[u])
		u++;
	u--;
	while (charinset(s1[u], set) == 1)
		u--;
	len = u - start + 1;
	return (ft_substr(s1, start, len));
}

/*int main()
{
	char *test = "alessandra";
 	printf("%s\n", ft_strtrim(test, "a"));
 	return 0;
}*/
