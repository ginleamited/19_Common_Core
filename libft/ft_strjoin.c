/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:37:31 by jilin             #+#    #+#             */
/*   Updated: 2024/10/22 22:43:47 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		i;
	size_t		j;
	char		*result;

	i = 0;
	j = 0;
	result = (char *) malloc(ft_strlen(s1)
			+ (ft_strlen(s2) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (s1[i])
		result[j++] = s1[i++];
	i = 0;
	while (s2[i])
		result[j++] = s2[i++];
	result[j] = 0;
	return (result);
}

// int	main(void)
// {
// 	char	s1[] = "HELLO";
// 	char	s2[] = "WORLD";
// 	char	*result;

// 	result = ft_strjoin(s1, s2);
// 	printf("%s\n", result);
// }