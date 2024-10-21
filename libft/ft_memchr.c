/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:27:38 by jilin             #+#    #+#             */
/*   Updated: 2024/10/22 00:21:42 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, size_t c, size_t n)
{
	unsigned char	*tmp_s;
	unsigned char	i;

	i = 0;
	tmp_s = (unsigned char *)s;
	while (i < n)
	{
		if (tmp_s[i] == (unsigned char)c)
		{
			return ((void *)tmp_s + i);
		}
		i++;
	}
	if (tmp_s[i] == '\0')
	{
		return ((void *)tmp_s + i);
	}
	return (0);
}
// int	main(void)
// {
// 	printf("%s\n", ft_memchr("salutmecjisjdaoijaisd", 'j', 10));
// 	printf("%s\n", memchr("salutmecjisjdaoijaisd", 'j', 10));
// }
