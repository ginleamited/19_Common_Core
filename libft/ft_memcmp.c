/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:41:43 by jilin             #+#    #+#             */
/*   Updated: 2024/10/28 18:33:37 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;
	size_t			i;

	i = 0;
	tmp_s1 = (void *)s1;
	tmp_s2 = (void *)s2;
	while (i < n && tmp_s1[i] == tmp_s2[i])
		i++;
	if (i == n)
		return (0);
	return (tmp_s1[i] - tmp_s2[i]);
}
// int	main(void)
// {
// 	printf("%d\n", ft_memcmp("saluto", "saluti", 5));
// 	printf("%d\n", memcmp("saluto", "saluti", 5));
// }

// EXPLANATION:
// Compare the memory value of two strings