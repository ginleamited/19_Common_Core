/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:45:03 by jilin             #+#    #+#             */
/*   Updated: 2024/10/17 19:43:03 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int	  i;

	i = 0;
	while(i < len)
	{
		((unsigned char *)b)[i] = c;
		i++;
	}
	return(b);
}

int main(void)
{
	int c = 'a';
	unsigned char b[] = "salut";

	printf("%s", ft_memset(b, c, 2));
}