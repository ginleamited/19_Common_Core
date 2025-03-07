#include "../inc/so_long.h"

int key_press(int key, t_game *game)
{
	ft_printf("Key pressed: %d\n", key); // Debug line
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
    exit_game(game);
    return (0);
}

void exit_game(t_game *game)
{
    int i;

    i = 0;
    while (i < game->rows && game->map[i])
    {
        free(game->map[i]);
        i++;
    }
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
}

void free_map(char **map, int rows)
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

void cleanup_game(t_game *game)
{
    if (game->map)
        free_map(game->map, game->rows);
    if (game->win)
        mlx_destroy_window(game->mlx, game->win);
    if (game->mlx)
    {
        mlx_destroy_display(game->mlx);
        free(game->mlx);
    }
}