#include "../inc/so_long.h"

int main(int ac, char **av)
{
    t_game game;

    if (ac != 2)
        return (ft_printf("ERROR: Invalid arguments\n"), 1);
    
    char *ext = ft_strrchr(av[1], '.');
    if (!ext || ft_strcmp(ext, ".ber") != 0)
        return (ft_printf("ERROR: Invalid map file\n"), 1);

    ft_memset(&game, 0, sizeof(t_game));
    
    if (!parse_map(&game, av[1]))
        return (ft_printf("ERROR: Invalid map\n"), 1);
    
    if (!init_game(&game))
        return (ft_printf("ERROR: Game init failed\n"), cleanup_game(&game), 1);
    
    render_map(&game);
    
    mlx_hook(game.win, 2, 1L<<0, key_press, &game);
    mlx_hook(game.win, 17, 0, close_window, &game);
    
    mlx_loop(game.mlx);
    
    cleanup_game(&game);
    return (0);
}