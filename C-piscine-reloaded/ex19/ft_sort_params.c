/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 22:11:27 by jilin             #+#    #+#             */
/*   Updated: 2024/10/08 22:49:06 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
}

int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while(s1[i] && s2[i] && s1[i] == s2[i])
    {
        i++;
    }
    return (s1[i] - s2[i]);
}

void ft_swap(char **a, char **b)
{
    char *tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(int ac, char **av)
{
    int i;
    int check;

    check = 1;
    while (check < ac - 1)
    {
        i = 1;
        while (i < ac - 1)
        {
            if (ft_strcmp(av[i], av[i + 1]) > 0)
            {
                ft_swap(&av[i], &av[i + 1]);
            }
            i++;
        }
        check++;
    }
    i = 1;
    while (i < ac)
    {
        ft_putstr(av[i]);
        ft_putchar('\n');
        i++;
    }
    return(0);
}