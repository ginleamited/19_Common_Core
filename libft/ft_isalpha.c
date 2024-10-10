/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 23:59:55 by jilin             #+#    #+#             */
/*   Updated: 2024/10/08 23:59:55 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_isalpha(int c)
{
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        return (1);
    return (0);
}

int main()
{
    char *str = "salut";  // Define a string to test
    int i = 0;

    while (str[i] != '\0') 
    {
        if (ft_isalpha(str[i]))
            printf("'%c' is alpha\n", str[i]);
        else 
            printf("'%c' is not alpha\n", str[i]);
        i++;
    }    

    return (0);
}