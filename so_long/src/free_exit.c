/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:41:13 by jilin             #+#    #+#             */
/*   Updated: 2025/03/13 17:13:31 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_map(char **map, int rows)
{
	int	y;

	if (!map)
		return ;
	y = -1;
	while (++y < rows)
		free(map[y]);
	free(map);
}

int	exit_game(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->rows && game->map[i])
		free(game->map[i]);
	free(game->map);
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->floor_img)
		mlx_destroy_image(game->mlx, game->floor_img);
	if (game->player_img)
		mlx_destroy_image(game->mlx, game->player_img);
	if (game->collectible_img)
		mlx_destroy_image(game->mlx, game->collectible_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx, game->exit_img);
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
