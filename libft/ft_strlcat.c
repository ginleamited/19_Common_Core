/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:25:10 by jilin             #+#    #+#             */
/*   Updated: 2024/10/17 19:43:30 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		i++;
	}
	return(0);
}

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int i;

	i = 0;
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);

	if(dst_len <= dstsize)
	{
		return(src_len + dstsize);
	}
	else if(dst_len > dstsize)
	{
		while(i < dstsize)
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		dst[dst_len + i] = '\0';
		return(src_len + dst_len);
	}
}