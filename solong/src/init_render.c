/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:41:07 by jilin             #+#    #+#             */
/*   Updated: 2025/03/16 14:09:41 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	init_mlx_and_window(t_game *game)
{
	int	window_width;
	int	window_height;

	window_width = game->cols * TILE_SIZE;
	window_height = game->rows * TILE_SIZE;
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error: Failed to initialize MLX\n");
		return (0);
	}
	game->win = mlx_new_window(game->mlx, window_width,
			window_height, "so_long");
	if (!game->win)
		return (0);
	return (1);
}

static void	*get_image_for_tile(t_game *game, int x, int y)
{
	char	tile;

	tile = game->map[y][x];
	if (tile == '1')
		return (game->wall_img);
	else if (tile == 'C')
		return (game->collectible_img);
	else if (tile == 'E')
		return (game->exit_img);
	else
		return (game->floor_img);
}

int	init_game(t_game *game)
{
	if (!init_mlx_and_window(game))
		return (0);
	if (!load_images(game))
		return (0);
	game->moves = 0;
	game->collected = 0;
    game->player_img = game->player_down;
	return (1);
}

void	render_game(t_game *game)
{
	int		x;
	int		y;
	void	*img;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols)
		{
			img = get_image_for_tile(game, x, y);
			mlx_put_image_to_window(game->mlx, game->win, img,
				x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->player_img,
		game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
	display_moves(game);
	render_enemies(game);
}
