/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:37:42 by jilin             #+#    #+#             */
/*   Updated: 2024/11/07 02:57:03 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_format(char c, va_list args);

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;
	int		i;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			count += printf_format(str[i], args);
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
//args for all the arguments
//the function ft_printf needs return a count to act like printf
//va_start : open variadic and start of the args is str
//Then we need to control args when % occurs
//The next character shouldn't be null and we go behind %
//Then call printf_format function by calling each functions
//If not % just write the string
//va_end : close the variadic

int	printf_format(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		count += ft_0xputpointerhex(va_arg(args, unsigned long long), 0);
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		count += ft_putunsignednbr(va_arg(args, unsigned int));
	else if (c == 'x')
		count += ft_putnbrhex(va_arg(args, unsigned int), 0);
	else if (c == 'X')
		count += ft_putnbrhex(va_arg(args, unsigned int), 1);
	else if (c == '%')
		count += ft_putchar('%');
	return (count);
}

//* MAIN
// int main (void)
// {
// 	printf("test jej kkskk%d", 44)
// }

//* EXPLANATION:
//printf will print count and string