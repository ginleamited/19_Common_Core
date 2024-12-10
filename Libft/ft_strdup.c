/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:24:15 by jilin             #+#    #+#             */
/*   Updated: 2024/10/30 13:51:13 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*dup;

	i = ft_strlen(src);
	dup = malloc(sizeof(char) * (i + 1));
	if (dup == NULL)
		return (NULL);
	ft_strlcpy(dup, src, i + 1);
	return (dup);
}

//* MAIN
// int	main(void)
// {
// 	char	*src = NULL;

// 	printf("%s\n", strdup(src));
// printf("%s\n", ft_strdup(src));
// }

//* EXPLANATION:
// Duplicate 