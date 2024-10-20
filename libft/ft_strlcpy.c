/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:28:14 by jilin             #+#    #+#             */
/*   Updated: 2024/10/21 01:15:13 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = ft_strlen(src);
	if (dstsize > i + 1)
	{
		ft_memcpy(dst, src, i + 1);
	}
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = 0;
	}
	return (src_len);
}
size_t	i;
{
if (dstsize == 0)
	return (ft_strlen(src));

i = 0;
while (src[i] != '\0' && i < dstsize - 1)
{
	dst[i] = src[i]
	i++;
}
dst[i] = '\0';

return (ft_strlen(src));
}
