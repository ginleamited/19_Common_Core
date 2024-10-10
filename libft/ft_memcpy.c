/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:23:45 by jilin             #+#    #+#             */
/*   Updated: 2024/10/10 19:48:30 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_memcpy(void *dst, const void *src, size_t n)
{
    if (!dst && !src)
        return NULL;

     (unsigned char *)tmp_src = (unsigned char *)src;
     (unsigned char *)tmp_dst = (unsigned char *)dst;
    
    while(n > 0)
    {
        *tmp_dst++ = *tmp_src++;
        n--;
    }
    return dst;
}