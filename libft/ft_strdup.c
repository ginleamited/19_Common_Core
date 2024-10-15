/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:24:15 by jilin             #+#    #+#             */
/*   Updated: 2024/10/15 20:03:42 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlen (char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);
}

size_t ft_strcpy (char *dst, char *src)
{
    int i;

    i = 0;
    while (src[i])
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (0);
}

char *ft_strdup(char *src)
{
    int i;
    char *dup;

    i = ft_strlen(src);
    dup = (malloc(sizeof(char) * (i + 1)));
    if (dup == NULL)
        return (NULL);
    ft_strcpy(dup, src);
    return (dup);
}

int main ()
{
        char src [] = "salut";
        printf("%s", ft_strdup(src));
        return (0);
}