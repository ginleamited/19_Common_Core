#include "../inc/so_long.h"

int init_game(t_game *game)
{
    int width, height;

    game->mlx = mlx_init();
    if (!game->mlx)
        return (0);

    int window_width = game->cols * TILE_SIZE;
	int window_height = game->rows * TILE_SIZE;

	// Initialize the window
	game->win = mlx_new_window(game->mlx, window_width, window_height, "so_long");
    if (!game->win)
        return (0);

    game->wall_img = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", &width, &height);
    game->floor_img = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm", &width, &height);
    game->player_img = mlx_xpm_file_to_image(game->mlx, "assets/player.xpm", &width, &height);
    game->collectible_img = mlx_xpm_file_to_image(game->mlx, "assets/collectibles.xpm", &width, &height);
    game->exit_img = mlx_xpm_file_to_image(game->mlx, "assets/exit.xpm", &width, &height);

    if (!game->wall_img || !game->floor_img || !game->player_img || !game->collectible_img || !game->exit_img)
        return (0);
    game->moves = 0;
    return (1);
}

void *get_image_for_tile(t_game *game, int x, int y)
{
    char tile = game->map[y][x];

    if (tile == '1')
        return (game->wall_img);
    else if (tile == 'C')
        return (game->collectible_img);
    else if (tile == 'E')
        return (game->exit_img);
    else
        return (game->floor_img);
}

void render_map(t_game *game)
{
    int x;
    int y;
    void *img;

    y = 0;
    while (y < game->rows)
    {
        x = 0;
        while (x < game->cols)
        {
            img = get_image_for_tile(game, x, y);
            mlx_put_image_to_window(game->mlx, game->win, img, x * TILE_SIZE, y * TILE_SIZE);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(game->mlx, game->win, game->player_img,
                            game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);

    char moves_str[20];
    sprintf(moves_str, "Moves: %d", game->moves);
    mlx_string_put(game->mlx, game->win, 10, 20, 0xFFFFFF, moves_str);
}