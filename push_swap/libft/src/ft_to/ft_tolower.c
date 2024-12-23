/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:28:39 by jilin             #+#    #+#             */
/*   Updated: 2024/12/17 18:11:22 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

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