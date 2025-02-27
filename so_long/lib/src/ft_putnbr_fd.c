/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:21:06 by jilin             #+#    #+#             */
/*   Updated: 2025/01/13 00:36:18 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
		ft_putnbr_fd(n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putchar_fd((n % 10) + 48, fd);
	}
	else
	{
		ft_putchar_fd((n + 48), fd);
	}
}

//* MAIN
// int main()
// {
//     ft_putnbr_fd(42, 1);
//     printf("\n");
//     ft_putnbr_fd(-42, 1);
//     printf("\n");
//     ft_putnbr_fd(0, 1);
//     printf("\n");
//     ft_putnbr_fd(-2147483648, 1);
//     printf("\n");
//     ft_putnbr_fd(2147483647, 1);
//     printf("\n");
//     return 0;
// }

//* EXPLANATION
// We need to handle the INT_MIN this is why the first condition

//? First let's handle n < 0
// print '-'
// put n in positive
// use recursive on n after it become positive

//? n > 9
// n will be divided by 10 and  recursively calls the function
// when it reaches to the first number, it will begin to modulo
// dozen by dozen, so it will print from left to right

//* EXAMPLE
// n = -1234
// n < 0 is true, prints -, then converts n to 1234.
// Calls ft_putnbr_fd(1234, 1).
// For 1234, it calls ft_putnbr_fd(123, 1).
// For 123, it calls ft_putnbr_fd(12, 1).
// For 12, it calls ft_putnbr_fd(1, 1).
// For 1, it prints 1
// Back to 12, prints 2
// Back to 123, prints 3
// Back to 1234, prints 4