/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 01:29:37 by jilin             #+#    #+#             */
/*   Updated: 2024/10/25 00:46:14 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(const char *s, char c)
{
	
}

static int	word_counter(const char *str, char c)
{
	int	i;
	int	count;
	int	x;

	i = 0;
	count = 0;
	x = 0;
	while (str[i])
	{
		if (str[i] != c && x == 0)
		{
			x = 1;
			count++;
		}
		else if (str[i] == c)
			x = 0;
		i++;
	}
	return (count);
}

static char	*fill_word(const char *str, int start, int end)
{
	char	*splitted_word;
	int		i;

	i = 0;
	splitted_word = malloc((end - start + 1) * sizeof(char));
	if (splitted_word)
		return (NULL);
	while (start < end)
	{
		splitted_word[i] = str[start];
		i++;
		start++;
	}
	splitted_word[i] = 0;
	return (splitted_word);
}

static void	*ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}
