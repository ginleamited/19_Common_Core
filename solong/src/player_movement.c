/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:40:48 by jilin             #+#    #+#             */
/*   Updated: 2025/03/15 16:46:59 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	check_enemy_collision(t_game *game, int new_x, int new_y)
{
	t_enemy	*enemy;

	enemy = game->enemies;
	while (enemy)
	{
		if (enemy->x == new_x && enemy->y == new_y)
		{
			ft_printf("💀 Game Over! You were caught by an enemy.\n");
			exit_game(game);
			return (0);
		}
		enemy = enemy->next;
	}
	return (1);
}

static void	handle_collectible_and_exit(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'C')
	{
		game->collected++;
		game->map[new_y][new_x] = '0';
	}
	if (game->map[new_y][new_x] == 'E' && game->collected == game->collectibles)
	{
		ft_printf("CONGRATS! Total moves: %d\n", game->moves);
		exit_game(game);
	}
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (!is_valid_move(game, new_x, new_y))
		return ;
	if (!check_enemy_collision(game, new_x, new_y))
		return ;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	player_direction(game, dx, dy);
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	handle_collectible_and_exit(game, new_x, new_y);
	render_map(game);
}

int	key_press(int key, t_game *game)
{
	ft_printf("Key pressed: %d\n", key);
	if (key == ESC)
		exit_game(game);
	else if (key == W || key == 119)
		move_player(game, 0, -1);
	else if (key == A || key == 97)
		move_player(game, -1, 0);
	else if (key == S || key == 115)
		move_player(game, 0, 1);
	else if (key == D || key == 100)
		move_player(game, 1, 0);
	return (0);
}
