/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:05:52 by jilin             #+#    #+#             */
/*   Updated: 2025/03/09 21:33:21 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	is_valid_move(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->cols || y >= game->rows)
		return (0);
	if (game->map[y][x] == '1')
		return (0);
	if (game->map[y][x] == 'E' && game->collected != game->collectibles)
		return (0);
	return (1);
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (!is_valid_move(game, new_x, new_y))
		return ;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	if (game->map[new_y][new_x] == 'C')
	{
		game->collected++;
		game->map[new_y][new_x] = '0';
	}
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	if (game->map[game->player_y][game->player_x] == 'E'
		&& game->collected == game->collectibles)
	{
		ft_printf("CONGRATS! Total moves: %d\n", game->moves);
		exit_game(game);
	}
	render_map(game);
}

int	key_press(int key, t_game *game)
{
	ft_printf("Key pressed: %d\n", key);
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
