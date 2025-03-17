/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:47:29 by jilin             #+#    #+#             */
/*   Updated: 2025/03/17 17:51:05 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../lib/inc/libft.h"
# include "../mlx/mlx.h"

# define TILE_SIZE 64
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100

typedef struct s_enemy
{
	int				x;
	int				y;
	struct s_enemy	*next;
}	t_enemy;

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
}	t_game;

// Map Parsing and backtracking
int		is_valid_move(t_game *game, int x, int y);
int		is_map_valid(t_game *g);
int		is_map_surrounded(t_game *g);
int		is_path_valid(t_game *g);
int		validate_map(t_game *game);
int		parse_map(t_game *game, char *file);
// Game Cleanup and Exit
void	free_map(char **map, int rows);
int		exit_game(t_game *game);
void	free_2d_map(void **arr, int height);
// Initialization and Rendering
int		init_game(t_game *game);
int		load_images(t_game *game);
void	render_game(t_game *game);
void	display_moves(t_game *game);
// Player Movement and Input
void	player_position(t_game *g);
void	player_direction(t_game *game, int dx, int dy);
void	move_player(t_game *game, int dx, int dy);
int		key_press(int key, t_game *game);
// Enemies
void	add_enemy(t_game *game, int x, int y);
void	detect_enemies(t_game *g, char *line, int y);
void	render_enemies(t_game *game);

#endif