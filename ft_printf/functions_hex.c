/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 22:23:02 by jilin             #+#    #+#             */
/*   Updated: 2024/11/06 00:56:37 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_0xputpointerhex(unsigned long nb, flag);
{
	int	count;
	
	count = 0;
	if (!nb)
		count += ft_putstr("NULL");
	if (nb)
	{
		count += ft_putstr("0x");//0x is the start of a hex adress
		count += ft_putpointer_hex(nb, flag);//print the hex value of the pointer
	}
	return (count);
}
//print the mem address of a pointer in hex format
//nb : printed in hex
//flag : lower or uppercase

int	ft_putpointerhex(unsigned long nb, flag);
{
	char *base;
	int count;

	count = 0;
	base = "0123456789abcdef";
	if (flag == 1)
		base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		count += ft_putpointerhex((nb / 16), flag);//divide recursively each nb
		count += ft_putchar(base[nb % 16]);//modulo in reverse after each nb being divided, so first modulo the smallest number, last modulo the biggest number
	}
	else
		count += ft_putchar(base[nb % 16]);//modulo the smallest number
	return (count);
}
//print a nb in hex format

int	ft_putnbrhex(unsigned int nb, flag);
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	if (flag == 1)
		base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		count += ft_putpointerhex((nb / 16), flag);//divide recursively each nb
		count += ft_putchar(base[nb % 16]);//modulo in reverse after each nb being divided, so first modulo the smallest number, last modulo the biggest number
	}
	else
		count += ft_putchar(base[nb % 16]);//modulo the smallest number
	return (count);
}

//* EXPLANATION:
