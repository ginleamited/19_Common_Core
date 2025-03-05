/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:50:07 by jilin             #+#    #+#             */
/*   Updated: 2025/03/05 15:03:02 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int main(int ac, char **av)
{
	t_game game;

	if (ac != 2)
	{
		ft_printf("Usage: ./so_long map.ber\n");
		return (1);
	}
}

char *ext = ft_strrchr(av[1], '.');
if (!ext || ft_strcmp(ext, ".ber") != 0)
{
	ft_printf("No .ber type map found");
	return (1);
}

ft_memset(&game, 0, sizeof())