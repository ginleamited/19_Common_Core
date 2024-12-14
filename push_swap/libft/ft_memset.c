/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:45:03 by jilin             #+#    #+#             */
/*   Updated: 2024/10/30 13:50:59 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = c;
		i++;
	}
	return (b);
}

//* MAIN
// int	main(void)
// {
// 	int	c;
// 	unsigned char	b[] = "salut";

// 	printf("%s", ft_memset(b, c, 2));
// }

//* EXPLANATION:
// Write len times of character c in b