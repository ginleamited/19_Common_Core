/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:41:13 by jilin             #+#    #+#             */
/*   Updated: 2025/03/14 04:26:29 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	free_images(t_game *game)
{
	if (game->player_up)
		mlx_destroy_image(game->mlx, game->player_up);
	if (game->player_down)
		mlx_destroy_image(game->mlx, game->player_down);
	if (game->player_left)
		mlx_destroy_image(game->mlx, game->player_left);
	if (game->player_right)
		mlx_destroy_image(game->mlx, game->player_right);
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->floor_img)
		mlx_destroy_image(game->mlx, game->floor_img);
	if (game->collectible_img)
		mlx_destroy_image(game->mlx, game->collectible_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx, game->exit_img);
	if (game->enemy_img)
		mlx_destroy_image(game->mlx, game->enemy_img);
}

void	free_map(char **map, int rows)
{
	int	i;

	if (!map)
		return ;
	i = -1;
	while (++i < rows)
		free(map[i]);
	free(map);
}

int	exit_game(t_game *game)
{
	free_enemies(game->enemies);
	free_map(game->map, game->rows);
	free_images(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
	return (0);
}

void	free_2d_array(void **arr, int height)
{
	int	i;

	if (!arr)
		return ;
	i = -1;
	while (++i < height)
		free(arr[i]);
	free(arr);
}
