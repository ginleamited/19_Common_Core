/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:45:03 by jilin             #+#    #+#             */
/*   Updated: 2025/03/05 15:19:35 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

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
// 	int	c = 'a';
// 	unsigned char	b[] = "salut";

// 	ft_printf("%s\n", (char *)ft_memset(b, c, 4));
// }

//* EXPLANATION:
// Write len times of character c in b