/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 22:50:58 by jilin             #+#    #+#             */
/*   Updated: 2024/10/08 23:16:31 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        i++;
    }
    return(i);
}

int *ft_strcpy(char *dest, char*src)
{
    int i;

    i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
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
    return(dup);
}

int main()
{
    char src [] = "abc";
    char* dest;
    dest = ft_strdup(src);
    printf("%s", ft_strdup(dest));
    return (0);
}
