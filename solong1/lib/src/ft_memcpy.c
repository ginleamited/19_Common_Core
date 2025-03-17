/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:40:42 by jilin             #+#    #+#             */
/*   Updated: 2025/01/13 00:36:18 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp_src;
	unsigned char	*tmp_dst;

	if (!dst && !src && n > 0)
		return (NULL);
	tmp_src = (unsigned char *)src;
	tmp_dst = (unsigned char *)dst;
	while (n > 0)
	{
		*(tmp_dst++) = *(tmp_src++);
		n--;
	}
	return (dst);
}

//* MAIN
// int	main(void)
// {
// 	char	src[];
// 	char	dst[20];

// 	src[] = "source";
// 	ft_memcpy(dst, src, 2);
// 	dst[2] = '\0';
// 	printf("Destination: %s\n", dst);
// }

//* EXPLANATION:
// Copy src to dst

//* DEBUGGING:
// If both dst and src being NULL when n > 0. If both are 
// NULL with n > 0, it will return NULL instead of trying 
// to copy, thereby avoiding the crash.

// If only one of dst or src is NULL, the function will still 
// crash, maintaining the standard behavior for memcpy when 
// an invalid pointer is provided.