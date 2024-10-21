/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:21:03 by jilin             #+#    #+#             */
/*   Updated: 2024/10/22 00:24:32 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new_string;

	i = 0;
	while (s[i])
		i++;
	if (i < start)
		return (ft_strdup(" "));
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
// int	main(void)
// {
// 	printf("%s", ft_substr("Bonjour comment ca va?", 5, 8));
// }