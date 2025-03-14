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

typedef struct s_enemy
{
    int x;
    int y;
    struct s_enemy *next;
} t_enemy;

typedef struct s_game
{
	// MLX & Window
	void	*mlx;
	void	*win;
	// Map Data
	char	**map;
	int		rows;
	int		cols;
	// Player Data
	int		player_x;
	int		player_y;
	void	*player_img;
	void	*player_up;
	void	*player_down;
	void	*player_left;
	void	*player_right;
	// Enemy Data
	void	*enemy_img;
	t_enemy	*enemies;
	// Collectibles & Exit
	int		collectibles;
	int		collected;
	void	*collectible_img;
	void	*exit_img;
	// Map Textures
	void	*wall_img;
	void	*floor_img;
	// Game Stats
	int		moves;
	int		move_dx;
	int		move_dy;
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

// Enemies
void	add_enemy(t_game *game, int x, int y);
void	detect_enemies(t_game *g, char *line, int y);
void	render_enemies(t_game *game);
void	free_enemies(t_enemy *enemies);

#endif