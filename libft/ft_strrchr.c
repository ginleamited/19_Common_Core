/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 22:05:55 by jilin             #+#    #+#             */
/*   Updated: 2024/10/18 21:53:00 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
		i--;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)(s + i));
	return (0);
}
/*
int main(void)
{
	printf("%s\n", ft_strrchr("salutmecjisjdaoijaisd", 'j'));
	printf("%s\n", strrchr("salutmecjisjdaoijaisd", 'j'));
}
*/