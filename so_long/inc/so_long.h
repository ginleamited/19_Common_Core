#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../lib/inc/libft.h"
# include "../mlx/mlx.h"

# define TILE_SIZE 32
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

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
	int		moves;
}	t_game;

int parse_map(t_game *game, char *file);
int validate_map(t_game *game);
int init_game(t_game *game);
void render_map(t_game *game);
int key_press(int key, t_game *game);
void move_player(t_game *game, int dx, int dy);
void exit_game(t_game *game);
int close_window(t_game *game);
void cleanup_game(t_game *game);

#endif