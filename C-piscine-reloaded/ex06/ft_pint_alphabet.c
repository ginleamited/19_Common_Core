/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pint_alphabet.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 21:55:11 by jilin             #+#    #+#             */
/*   Updated: 2024/10/08 21:55:19 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_print_alphabet(void)
{
    char letter = 'a';

    while (letter <= 'z')
    {
        ft_putchar(letter);
        letter++;
    }
}
/*
int main()
{
    ft_print_alphabet();
    return(0);
}
*/
