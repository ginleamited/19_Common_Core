/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:35:08 by jilin             #+#    #+#             */
/*   Updated: 2025/02/21 22:28:58 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

long	ft_atoi(const char *str)
{
	int		i;
	int		signe;
	long	resultat;

	i = 0;
	signe = 1;
	resultat = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == 45)
			signe *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		resultat *= 10;
		resultat += str[i] - 48;
		i++;
	}
	return (resultat * signe);
}

//* MAIN
// int	main(void)
// {
// 	 char	*src = "-2147483649000000000999999989";
// 	printf("%d\n", ft_atoi(src));
// 	printf("%d\n", atoi(src));
// }

//* EXPLANATION:
//? This function converts a string to an integer
//  It skips the white spaces and tabs
//  If the first character is a sign, it will store the sign
//  It will loop through the string and convert the string to an integer
//  If the number is negative, it will multiply the result by -1