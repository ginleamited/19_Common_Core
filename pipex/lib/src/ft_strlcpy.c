/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:28:14 by jilin             #+#    #+#             */
/*   Updated: 2025/01/13 00:36:18 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = ft_strlen(src);
	if (dstsize == 0)
		return (ft_strlen(src));
	else if (dstsize > i + 1)
	{
		ft_memcpy(dst, src, i + 1);
	}
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = 0;
	}
	return (i);
}

//* MAIN
// int	main(void)
// {
// 	char		dst[10];
// 	const char	src[] = "salut";

// 	printf("%zu\n%s\n", ft_strlcpy(dst, src, 10), dst);
// 	printf("%lu\n%s\n", strlcpy(dst, src, 10), dst);
// }

//* EXPLANATION:
// Copy src in dst and nul terminate