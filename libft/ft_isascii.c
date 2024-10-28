/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:31:25 by jilin             #+#    #+#             */
/*   Updated: 2024/10/26 20:43:32 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_isascii(size_t c)
{
	if (c <= 127)
		return (1);
	return (0);
}

// we don't write c >= 0 because size_t is unsigned integer
// and is always non-negative
// If it's in ascii