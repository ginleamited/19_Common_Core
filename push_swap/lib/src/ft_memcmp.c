/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:41:43 by jilin             #+#    #+#             */
/*   Updated: 2025/01/13 00:36:18 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

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

//* MAIN
// int	main(void)
// {
// 	printf("%d\n", ft_memcmp("saluto", "saluti", 5));
// 	printf("%d\n", memcmp("saluto", "saluti", 5));
// }

//* EXPLANATION:
// Compare the memory value of two strings

//* DEBUGGING:
// Removed the (tmp_s1[i] && tmp_s2[i]) condition to ensure 
// that the comparison does not stop at a null character.
// just like in the standard memcmp

// The loop now only checks if i < n and stops as soon 
// as tmp_s1[i] differs from tmp_s2[i].

// If i reaches n, this means all n bytes are identical, 
// so the function returns 0.

// If a difference is found before reaching n, 
// it returns the difference between tmp_s1[i] and tmp_s2[i], 
// as expected in memcmp.
