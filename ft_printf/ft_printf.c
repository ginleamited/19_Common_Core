/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:37:42 by jilin             #+#    #+#             */
/*   Updated: 2024/11/05 23:26:29 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	printf_format(char c, va_list args);

int	ft_printf(const char *str, ...)
{
	int count;
	va_list args;//args for all the arguments
	int i;

	i = 0;//to iterate
	count = 0;//the function printf needs return a count
	va_start(args, str); //open variadic and start of the args is str
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')//to control args
		{
			i++;//go behind %
			count += printf_format(str[i], args);//call each functions
		}
		else
			count += write(1, &str[i], 1);//just write
		i++;
	}
	va_end(args);//close the variadic
	return (count);
}

int	printf_format(char c, va_list args)
{
	int count;
	
	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(args, int));
	if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	if (c == 'p')
		count += ft_putpointerhex(va_arg(args,));
	if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(args, int));
	if (c == 'u')
		count += ft_putunsignednbr(va_arg(args, int));
	if (c == 'x')
		count += ft_putnbrhex(va_arg(args,));
	if (c == 'X')
		count += ft_putnbrhex(va_arg(args,));
	if (c == '%')
		count += ft_putchar('%');
	return (count);
}

//* MAIN
// int main (void)
// {
// 	printf("test jej kkskk%d", 44)
// }

//* EXPLANATION:
