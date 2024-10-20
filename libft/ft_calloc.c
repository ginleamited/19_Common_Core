/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:56:31 by jilin             #+#    #+#             */
/*   Updated: 2024/10/21 00:47:00 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;
	int				i;

	tmp = malloc(count * size);
	i = 0;
	if (!tmp)
		return (NULL);
	while (i < count * size)
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}
/*
int	main(void)
{
	int	*arr;

	arr = (int *)ft_calloc(3, sizeof(int));
 	if (arr == NULL)
		return (1);
	printf("%d %d %d\n", arr[0], arr[1], arr[2]);
	free(arr);
}
*/