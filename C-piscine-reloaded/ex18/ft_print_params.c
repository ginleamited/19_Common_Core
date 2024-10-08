/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 21:56:11 by jilin             #+#    #+#             */
/*   Updated: 2024/10/08 22:04:52 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putstr(char *str)
{
    int j;

    j = 0;
    while (str[j])
    {
        write(1, &str[j], 1);
        j++;
    }
}

int main(int ac, char **av)
{
    int i;

    i = 1;
    while(ac > 1 && av[i])
    {
        ft_putstr(av[i]);
        write(1, "\n", 1);
        i++;
    }
    return (0);
}