/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:51:24 by jilin             #+#    #+#             */
/*   Updated: 2025/03/17 17:51:25 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	player_position(t_game *g)
{
	int	y;
	int	x;

	y = -1;
	while (++y < g->rows)
	{
		x = -1;
		while (++x < g->cols)
		{
			if (g->map[y][x] == 'P')
			{
				g->player_x = x;
				g->player_y = y;
				return ;
			}
		}
	}
}

void	player_direction(t_game *game, int dx, int dy)
{
	if (dx == 1)
		game->player_img = game->player_right;
	else if (dx == -1)
		game->player_img = game->player_left;
	else if (dy == 1)
		game->player_img = game->player_down;
	else if (dy == -1)
		game->player_img = game->player_up;
}
