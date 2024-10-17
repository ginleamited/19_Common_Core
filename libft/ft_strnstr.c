/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 20:18:02 by jilin             #+#    #+#             */
/*   Updated: 2024/10/17 20:48:14 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		if (haystack[i] == (unsigned char)needle)
		{
			while (needle[j])
			{
				
				j++;
			}
		}
		return ((char *)haystack + i);
		i++;
	}
	if (haystack[i] == '\0')
	{
		return ((char *)haystack + i);
	}
	return (0);
}

int	main(void)
{
	printf("%s\n", ft_strnstr("salutmecjisjdaoijaisd", "m", 13));
	printf("%s\n", strnstr("salutmecjisjdaoijaisd", "m", 13));
}
