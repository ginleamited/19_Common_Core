#include "../inc/so_long.h"

static int	load_map_images(t_game *game, int *width, int *height)
{
	game->wall_img = mlx_xpm_file_to_image(game->mlx,
			"assets/wall.xpm", width, height);
	game->floor_img = mlx_xpm_file_to_image(game->mlx,
			"assets/floor.xpm", width, height);
	game->collectible_img = mlx_xpm_file_to_image(game->mlx,
			"assets/collectibles.xpm", width, height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx,
			"assets/exit.xpm", width, height);
	game->enemy_img = mlx_xpm_file_to_image(game->mlx,
			"assets/enemy.xpm", width, height);
	return (1);
}

static int	load_player_images(t_game *game, int *width, int *height)
{
	game->player_up = mlx_xpm_file_to_image(game->mlx,
			"assets/player_up.xpm", width, height);
	game->player_down = mlx_xpm_file_to_image(game->mlx,
			"assets/player_down.xpm", width, height);
	game->player_left = mlx_xpm_file_to_image(game->mlx,
			"assets/player_left.xpm", width, height);
	game->player_right = mlx_xpm_file_to_image(game->mlx,
			"assets/player_right.xpm", width, height);
	return (1);
}

static int	check_images_loaded(t_game *game)
{
	if (!game->wall_img || !game->floor_img || !game->collectible_img
		|| !game->exit_img || !game->player_up || !game->player_down
		|| !game->player_left || !game->player_right || !game->enemy_img)
		return (0);
	return (1);
}

int	load_images(t_game *game)
{
	int	width;
	int	height;

	load_map_images(game, &width, &height);
	load_player_images(game, &width, &height);
	if (!check_images_loaded(game))
		return (0);
	game->player_img = game->player_down;
	return (1);
}
