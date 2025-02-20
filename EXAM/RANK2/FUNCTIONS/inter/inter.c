/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 01:54:01 by jilin             #+#    #+#             */
/*   Updated: 2025/02/20 22:25:50 by jilin            ###   ########.fr       */
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
		while (av[2][i])
		{
			lookup[(unsigned char)av[2][i]] = 1; 
			i++;
		}
		i = 0;
		while (av[1][i])
		{
			if (lookup[(unsigned char)av[1][i]]) 
			{
				ft_putchar(av[1][i]); 
				lookup[(unsigned char)av[1][i]] = 0;
			}
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
//* EXPLANATION :
//? Write characters of av[1] if they exist in av[2]
//  In the first while loop, we mark characters present in av[2]
//  In the second while loop, we write characters from av[1] that are present in av[2]
//  We ensure unique output by marking characters as printed