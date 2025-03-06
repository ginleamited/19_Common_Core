#include "../inc/so_long.h"

int is_valid_move(t_game *game, int x, int y)
{
    if (x < 0 || y < 0 || x >= game->cols || y >= game->rows)
        return (0);
    if (game->map[y][x] == '1') // Block walls only
        return (0);
    if (game->map[y][x] == 'E' && game->collected != game->collectibles)
        return (0); // Block exit until all collectibles are gathered
    return (1); // Allow movement onto 'E' only if collectibles are collected
}

void move_player(t_game *game, int dx, int dy)
{
    int new_x = game->player_x + dx;
    int new_y = game->player_y + dy;

    if (!is_valid_move(game, new_x, new_y))
        return;

    game->moves++;
    ft_printf("Moves: %d\n", game->moves);

    // Handle collectibles
    if (game->map[new_y][new_x] == 'C')
    {
        game->collected++;
        game->map[new_y][new_x] = '0';
    }

    // Update player position FIRST
    game->map[game->player_y][game->player_x] = '0';
    game->player_x = new_x;
    game->player_y = new_y;

    // Check exit condition AFTER moving
    if (game->map[game->player_y][game->player_x] == 'E')
    {
        if (game->collected == game->collectibles)
        {
            ft_printf("CONGRATS! Total moves: %d\n", game->moves);
            exit_game(game);
        }
    }

    render_map(game);
}
