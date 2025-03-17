/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:56:23 by jilin             #+#    #+#             */
/*   Updated: 2025/01/13 00:36:18 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*resultat;

	if (!s || !f)
		return (NULL);
	i = 0;
	resultat = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!resultat)
		return (NULL);
	while (i < ft_strlen(s))
	{
		resultat[i] = f(i, s[i]);
		i++;
	}
	resultat[i] = 0;
	return (resultat);
}

//* ADD_FUNCTION
// char	my_func(unsigned int i, char c)
// {
// 	return (c + i + 1);
// }

//* MAIN
// int	main(void)
// {
// 	const char	*str = "Hello, World!";
// 	char		*result = ft_strmapi(str, my_func);

// 	if (result)
// 	{
// 		printf("%s\n", str);
// 		printf("%s\n", result);
// 		free(result);
// 	}
// 	else
// 		printf("Allocation failed.\n");
// }
//* EXPLANATION:
// First we malloc the memory for the size of *s and the NULL
// If allocation failed then return NULL
// Loop until the end of the string, apply the function to each
// index of the allocated string
