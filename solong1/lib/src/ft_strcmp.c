/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:34:04 by jilin             #+#    #+#             */
/*   Updated: 2025/03/05 19:09:24 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

// int	main(void)
// {
// 	const char *str1 = "hello";
// 	const char *str2 = "hellp";

// 	printf("ft_strcmp: %d\n", ft_strcmp(str1, str2));
// 	printf("ft_strncmp: %d\n", ft_strncmp(str1, str2, 5));

// 	return (0);
// }