/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:21:03 by jilin             #+#    #+#             */
/*   Updated: 2025/01/13 00:36:18 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new_string;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	if (i < start)
		return (ft_strdup(""));
	else if (len > i - start)
		len = i - start;
	new_string = ft_calloc(len + 1, sizeof(char));
	if (!new_string)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_string[i] = s[start + i];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}

//* MAIN
// int	main(void)
// {
// 	printf("%s", ft_substr("Bonjour comment ca va?", 5, 8));
// }

//* EXPLANATION:
// select only the part of the string that begin with start and 
// finish at start + len and the last is \0

//* DEBUGGING: 
// The issue here is that when start is greater than 
// or equal to the length of s, the function should return an empty 
// string, not a string with a single space. Currently, you’re returning 
// ft_strdup(" "), which returns a string with a space, not an empty string.
// You can fix it by returning ft_strdup("") instead.