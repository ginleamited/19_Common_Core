#include "../inc/so_long.h"

int main(int ac, char **av)
{
    t_game game;

    if (ac != 2)
    {
        ft_printf("ERROR: More than 2 arguments\n");
        return (1);
    }

    char *ext = ft_strrchr(av[1], '.');
    if (!ext || ft_strcmp(ext, ".ber") != 0)
    {
        ft_printf("ERROR: No .ber type map found\n");
        return (1);
    }

    ft_memset(&game, 0, sizeof(t_game));

    if (!parse_map(&game, av[1]))
    {
        ft_printf("ERROR: Invalid map\n");
        return (1);
    }

    if (!init_game(&game))
    {
        ft_printf("ERROR: Failed to initialize game\n");
        return (1);
    }

    render_map(&game);

    mlx_hook(game.win, 2, 1L << 0, key_press, &game);
    mlx_hook(game.win, 17, 1L << 17, close_window, &game);

    mlx_loop(game.mlx);

    cleanup_game(&game);
    return (0);
}