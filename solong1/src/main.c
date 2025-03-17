/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:05:45 by jilin             #+#    #+#             */
/*   Updated: 2025/03/13 19:09:32 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int ac, char **av)
{
	t_game	game;
	char	*ext;

	if (ac != 2)
		return (ft_printf("ERROR: Invalid arguments\n"), 1);
	ext = ft_strrchr(av[1], '.');
	if (!ext || ft_strcmp(ext, ".ber") != 0)
		return (ft_printf("ERROR: Invalid map file\n"), 1);
	ft_memset(&game, 0, sizeof(t_game));
	if (!parse_map(&game, av[1]))
		return (ft_printf("ERROR: Invalid map\n"), 1);
	if (!init_game(&game))
		return (ft_printf("ERROR: Game init failed\n"), exit_game(&game), 1);
	render_map(&game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 17, 0, (int (*)())exit_game, &game);
	mlx_loop(game.mlx);
	exit_game(&game);
	return (0);
}
