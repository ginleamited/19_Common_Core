/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:59:36 by jilin             #+#    #+#             */
/*   Updated: 2025/03/05 18:58:42 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	key_press (int key, t_game *game)
{
	if (key == ESC)
		exit_game(game);
	else if (key == W)
		move_player(game, 0, -1);
	else if (key == A)
		move_player(game, -1, 0);
	else if (key == S)
		move_player(game, 0, 1);
	else if (key == D)
		move_player(game, 1, 0);

	return (0);
}

int close_window(t_game *game)
{
	cleanup_game(game);
	exit_game(game);
	return (0);
}

void	exit_game(t_game *game)
{
	int i;
	
	i = 0;
	while (i < game->rows)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	
	mlx_destroy_image(game->mlx, game->wall_img);
	mlx_destroy_image(game->mlx, game->floor_img);
	mlx_destroy_image(game->mlx, game->player_img);
	mlx_destroy_image(game->mlx, game->collectible_img);
	mlx_destroy_image(game->mlx, game->exit_img);
	
	mlx_destroy_image(game->mlx, game->win);

	exit(0);
}

static void	free_map(char **map, int rows)
{
	int y;

	if (!map)
		return;
	y = 0;
	while (y < rows)
	{
		free(map[y]);
		y++;
	}
	free(map);
}

void	cleanup_game(t_game *game)
{
	if (game->win)
		mlx_destroy_image(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map)
		free_map(game->map, game->rows);
}
