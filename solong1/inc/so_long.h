#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../lib/inc/libft.h"
# include "../mlx/mlx.h"

# define TILE_SIZE 64
#define ESC 65307 // X11 keycode for ESC
#define W 119    // X11 keycode for 'w'
#define A 97     // X11 keycode for 'a'
#define S 115    // X11 keycode for 's'
#define D 100    // X11 keycode for 'd'

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		rows;
	int		cols;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		collected;
	void	*wall_img;
	void	*floor_img;
	void	*collectible_img;
	void	*exit_img;
	void	*player_img;
	void	*player_up;
	void	*player_down;
	void	*player_left;
	void	*player_right;
	int		moves;
}	t_game;

// Map Parsing and backtracking
int		is_map_characters(t_game *g);
int		is_map_rectangular(t_game *g);
int		is_map_surrounded(t_game *g);
int		is_path_valid(t_game *g);
int		validate_map(t_game *game);
int		parse_map(t_game *game, char *file);

// Game Cleanup and Exit
void	free_map(char **map, int rows);
int		exit_game(t_game *game);
void	free_2d_array(void **arr, int height);

// Initialization and Rendering
int		init_game(t_game *game);
void	render_map(t_game *game);
void	display_moves(t_game *game);

// Player Movement and Input
void	move_player(t_game *game, int dx, int dy);
int		key_press(int key, t_game *game);

#endif