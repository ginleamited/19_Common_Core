/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:27:38 by jilin             #+#    #+#             */
/*   Updated: 2025/01/13 00:36:18 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp_s;
	size_t			i;

	i = 0;
	tmp_s = (unsigned char *)s;
	while (i < n)
	{
		if (tmp_s[i] == (unsigned char)c)
			return ((void *)(tmp_s + i));
		i++;
	}
	return (0);
}

//* MAIN
// int	main(void)
// {
// 	printf("%s\n", ft_memchr("salutmecjisjdaoijaisd", 'j', 10));
// 	printf("%s\n", memchr("salutmecjisjdaoijaisd", 'j', 10));
// }

//* EXPLANATION:
// Find the letter in the memory

//* DEBUGGING: 
//The condition if (tmp_s[i] == '\0') in the loop after 
// i < n is redundant and incorrect. The function should stop reading 
// as soon as i == n is reached; no need to check for '\0'.

// The return value return ((void *)tmp_s + i); is incorrect because 
// it adds i to the tmp_s pointer before casting to void *. Instead, 
// it should add i after casting to void *.