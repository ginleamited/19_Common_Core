/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:28:14 by jilin             #+#    #+#             */
/*   Updated: 2024/10/15 19:03:00 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);
}
void *ft_memcpy(void *dst, const void *src, size_t n)
{
    unsigned char *tmp_src;
    unsigned char *tmp_dst;
    
    if (dst == 0 || src == 0)
        return (dst);

     tmp_src = (unsigned char *)src;
     tmp_dst = (unsigned char *)dst;
    
    while(n > 0)
    {
        *(tmp_dst++) = *(tmp_src++);
        n--;
    }
    return (dst);
}

size_t ft_strlcpy (char *dst, const char *src, size_t dstsize)
{
    size_t src_len;

    src_len = ft_strlen(src);


    if (dstsize > src_len + 1)
    {
        ft_memcpy(dst, src, src_len + 1);
    }

    else if (dstsize != 0)
    {
        ft_memcpy(dst, src, dstsize - 1);
        dst[dstsize - 1] = 0;
    }
    return (src_len);
}