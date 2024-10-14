/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:06:24 by jilin             #+#    #+#             */
/*   Updated: 2024/10/14 20:24:59 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t len)
{
    unsigned char *tmp_src;
    unsigned char *tmp_dst;
    size_t i;

    if (!dst && !src)
        return (NULL);
    
    tmp_src = (unsigned char*) src;
    tmp_dst = (unsigned char*) dst;
    i = 0;

    if (tmp_dst > tmp_src)
    {
        while (len > 0)
        {
            tmp_dst[len] = tmp_src[len];
            len--;
        }
    }
    if (tmp_dst < tmp_src)
    {
        while (i < len)
        {
            tmp_dst[i] = tmp_src[i];
            i++;
        }
    }
    return (dst);

}