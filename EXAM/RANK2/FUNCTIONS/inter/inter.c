/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 01:54:01 by jilin             #+#    #+#             */
/*   Updated: 2025/02/20 10:48:59 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(char c);

int	main(int ac, char **av)
{
	int	i = 0, j;
	int	lookup[256] = {};

	if (ac == 3)
	{
		// looping over the whole string
		while (av[1][i])
		{
			j = 0;
			// comparing against every character in the
			// second string
			while (av[2][j])
			{
				// checking if characters are the same
				// as well as checking in the lookup
				// table if the character not already
				// found
				if (av[1][i] == av[2][j] && !lookup[(int)av[2][j]])
				{
					// marking the character found
					// in the lookup table
					lookup[(int)av[2][j]] = 1;
					// writing the character
					// to the screen
					ft_putchar(av[2][j]);
				}
				j++;
			}
			i++;
		}
	}
	ft_putchar('\n');
}

int	ft_putchar(char c)
{
	return write(1, &c, 1);
}

#include <unistd.h>

int ft_putchar(char c);

int main(int ac, char **av)
{
    int i = 0;
    int lookup[256] = {0}; // Lookup table to track characters

    if (ac == 3)
    {
        // Mark characters from the second string (av[2]) in the lookup table
        while (av[2][i])
        {
            lookup[(int)av[2][i]] = 1;
            i++;
        }

        i = 0;
        // Iterate through the first string (av[1]) and print characters
        // that are present in the second string (av[2])
        while (av[1][i])
        {
            if (lookup[(int)av[1][i]])
            {
                ft_putchar(av[1][i]);
                lookup[(int)av[1][i]] = 0; // Mark as printed to avoid duplicates
            }
            i++;
        }
    }
    ft_putchar('\n');
    return 0; // Return 0 to indicate successful execution
}

int ft_putchar(char c)
{
    return write(1, &c, 1);
}