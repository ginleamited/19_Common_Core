/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 22:43:19 by jilin             #+#    #+#             */
/*   Updated: 2025/01/12 23:32:31 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

char	*ft_strdup(char *src)
{
	int		i;
	int		j;
	char	*dup;

	if (!src)
		return (NULL);
	j = ft_strlen(src);
	dup = malloc(j + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < j)
	{
		dup[i] = src[j];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		i;
	size_t		j;
	char		*result;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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
	new_string = malloc(len + 1);
	if (!new_string || new_string == 0)
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

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}
