/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:21:32 by jilin             #+#    #+#             */
/*   Updated: 2025/03/26 14:23:16 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return (write(1, "(null)", 6));
	i = 0;
	while (str[i])
	{
		if (ft_putchar(str[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}
//In printf, when it's NULL, output (null)

int ft_putnbr(int nb)
{
    long div = nb;
    int count = 0;
    int ret;
    if (div < 0)
    {
        ret = ft_putchar('-');
        if (ret == -1)
            return (-1);
        count += ret;
        div = -div;
    }
    if (div > 9)
    {
        ret = ft_putnbr(div / 10);
        if (ret == -1)
            return (-1);
        count += ret;
    }
    ret = ft_putchar((div % 10) + 48);
    if (ret == -1)
        return (-1);
    return (count + ret);
}

int	ft_unsignednbr(unsigned int nb)
{
	int		count;

	count = 0;
	if (nb > 9)
		count += ft_unsignednbr(nb / 10);
	nb = nb % 10;
	return (count += ft_putchar(nb + 48), count);
}
