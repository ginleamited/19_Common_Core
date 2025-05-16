/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:23:52 by jilin             #+#    #+#             */
/*   Updated: 2025/01/13 00:36:18 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

//* ADD_FUNCTION
void	to_upper(unsigned int i, char *c)
{
	(void)i;
	*c = ft_toupper(*c);
}

//* MAIN
// int	main(void)
// {
// 	char	str[] = "hello world";

// 	ft_striteri(str, to_upper);
// 	printf("%s\n", str);
// }

//* EXPLANATION
// Just like the strmapi but here we just apply the function
// in the original string with the address of the original string

// In the to_upper function, we dereference the pointer c to 
// give us the character that c points to.
// If *c initially pointed 'a', it now points 'A'

// When a char is passed to a function expecting an int,
// it's automatically promoted to an int.
// This means that if you pass a char like 'a', 
// its ASCII value (97) is passed to the function as an int.