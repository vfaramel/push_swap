/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvega-ja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:23:55 by vvega-ja          #+#    #+#             */
/*   Updated: 2023/03/30 14:22:37 by vvega-ja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*str;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		str = (char *) malloc(sizeof(*str) * (len1 + len2 + 1));
		if (str == NULL)
			return (NULL);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
			str[len1++] = s2[i];
		str[len1] = '\0';
		return (str);
	}
	return (NULL);
}
/*int main()
{
	
	char s1[] = "stringa1";
	char s2[] = "stringa2";

	char* dest = ft_strjoin(s1, s2);
	printf("%s\n", dest);

	return 0;
}*/
