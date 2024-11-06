/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:21:32 by jilin             #+#    #+#             */
/*   Updated: 2024/11/07 00:14:57 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	long	div;
	int		count;

	count = 0;
	div = nb;
	if (div < 0)
	{
		count += ft_putchar('-');
		div = -div;
	}
	if (div > 9)
		count += ft_putnbr(div / 10);
	nb = div % 10;
	count += ft_putchar(nb + 48);
	return (count);
}

int	ft_putunsignednbr(int nb)
{
	int		count;

	count = 0;
	if (nb > 9)
		count += ft_putnbr(nb / 10);
	nb = nb % 10;
	count += ft_putchar(nb + 48);
	return (count);
}
