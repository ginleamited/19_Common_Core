/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 22:05:55 by jilin             #+#    #+#             */
/*   Updated: 2025/01/13 00:36:18 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

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
	if (i == -0 && (s[i] != (unsigned char) c))
		return (0);
	return ((char *)(s + i));
}

//* MAIN
// int main(void)
// {
// 	printf("%s\n", ft_strrchr("salutmecjisjdaoijaisd", 'j'));
// 	printf("%s\n", strrchr("salutmecjisjdaoijaisd", 'j'));
// }

//* EXPLANATION:
// find the last occurence of the letter