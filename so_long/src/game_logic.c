/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:44:58 by jilin             #+#    #+#             */
/*   Updated: 2025/03/05 18:30:55 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	is_valid_move(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->cols || y >= game->rows)
		return (0);
	if (game->map[y][x] == '1')
		return (0);
	return (1);
}

void	move_player(t_game *game, int dx, int dy)
{
	int new_x = game->player_x + dx;
	int new_y = game->player_y + dy;

	if (!is_valid_move(game, new_x, new_y))
		return ;
	game->moves++;
	ft_printf("Moves: %d\n", (int)game->moves);
	if (game->map[new_y][new_x] == 'C')
	{
		game->collected++;
		game->map[new_y][new_x] = '0';
	}
	if (game->map[new_y][new_x] == 'E')
	{
		if (game->collected == game->collectibles)
		{
			ft_printf("CONGRATS!!! Total moves: %d\n, game->moves");
			exit_game(game);
		}
		return ;
	}
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;

	render_map(game);
}