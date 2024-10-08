/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 21:56:52 by jilin             #+#    #+#             */
/*   Updated: 2024/10/08 21:57:22 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_recursive_factorial(int nb)
{
    if (nb < 0)
        return (0);
    if (nb == 0)
        return (1);
    else
        return (nb * ft_recursive_factorial(nb - 1));
}
/*
#include <stdio.h>

int main()
{
    printf("%d", ft_recursive_factorial(4));
    return(0);
}
*/