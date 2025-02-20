/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:12:41 by jilin             #+#    #+#             */
/*   Updated: 2025/02/20 22:27:15 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	int i = 0;
	int lookup[256] = {0};
	if (ac == 3)
	{
		while (av[1][i])
		{
			if (!lookup[(unsigned char)av[1][i]])
			{
				ft_putchar(av[1][i]);
				lookup[(unsigned char)av[1][i]] = 1; 
			}
			i++;
		}
		i = 0;
		while (av[2][i])
		{
			if (!lookup[(unsigned char)av[2][i]])
			{
				ft_putchar(av[2][i]);
				lookup[(unsigned char)av[2][i]] = 1; 
			}
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
//* EXPLANATION :
//? Write unique characters in the order from the left to the right 
//  So in the first while loop, we write characters from av[1] and mark them as printed
//  We reset i to 0 se we can iterate over av[2] again
//  In the second while loop, we write characters from av[2] that are not marked as printed