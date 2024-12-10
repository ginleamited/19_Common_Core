/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:28:39 by jilin             #+#    #+#             */
/*   Updated: 2024/10/30 13:51:58 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	{
		return (c + 32);
	}
	return (c);
}

//* MAIN
// int	main(void)
// {
// 	printf("%c\n", ft_tolower('A'));
// 	printf("%c\n", tolower('B'));
// }

//* EXPLANATION:
// put the capital letters in lower case