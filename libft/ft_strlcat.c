/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvega-ja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:39:23 by vvega-ja          #+#    #+#             */
/*   Updated: 2023/03/29 13:48:32 by vvega-ja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	src_i;
	size_t	dst_i;

	if (!dst && size == 0)
		return (0);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	src_i = 0;
	dst_i = dst_len;
	if (dst_len >= size)
		return (size + src_len);
	while (src[src_i] && (size-- - (dst_len + 1)) > 0)
		dst[dst_i++] = src[src_i++];
	dst[dst_i] = '\0';
	return (dst_len + src_len);
}
/*int main(void)
{
	const char src1[10]	= "ab";
	char dst1[10] = "123";

	char src[10] = "ab";
	char dst[10] = "123";

	size_t nb = 2;
	size_t nb2 = 2;
	//strcat(src, dest);
	printf("str: %ld \n", ft_strlcat(dst1, src1, nb));
	printf("str: %zu", ft_strlcat(dst, src, nb2));
	return (0);
}*/
