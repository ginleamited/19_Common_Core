/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:47:06 by jilin             #+#    #+#             */
/*   Updated: 2025/01/13 00:36:18 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	ft_count_size(const char *s1, const char *set)
{
	int	start;
	int	end;
	int	s_len;

	if (!s1 || !set)
		return (0);
	s_len = ft_strlen(s1);
	start = 0;
	end = s_len - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	if (end < start)
		return (0);
	return (end - start + 1);
}

// sizeof(char) means one byte bc char is one byte
// sizeof(int) means 4 bytes, and we can sizeof(int) * 4 if there is 4 numbers

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*new_result;
	int		start;
	int		size;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	size = ft_count_size(s1, set);
	new_result = malloc(sizeof(char) * (size + 1));
	if (!new_result)
		return (NULL);
	ft_strlcpy(new_result, &s1[start], (size + 1));
	new_result[size] = '\0';
	return (new_result);
}

//* MAIN
// int	main(void)
// {
// 	char *str_trimmed = ft_strtrim("   aab  aaHELddbabLObbb  aabb     ", "ab ");

// 	if (str_trimmed)
// 	{
// 		printf("Trimmed string: '%s'\n", str_trimmed);
// 		free(str_trimmed);
// 	}
// }

//* EXPLANATION: