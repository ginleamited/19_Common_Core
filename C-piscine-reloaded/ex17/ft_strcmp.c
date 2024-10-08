/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 21:56:30 by jilin             #+#    #+#             */
/*   Updated: 2024/10/08 21:56:47 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strcmp(char *s1, char*s2)
{
    int i;

    i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}
/*
#include <stdio.h>

int main()
{
    char s1[] = "abcde";
    char s2[] = "abce";
    printf("%d\n", ft_strcmp (s1, s2));
    return(0);
}
*/