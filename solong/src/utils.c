/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:40:54 by jilin             #+#    #+#             */
/*   Updated: 2025/03/15 16:44:55 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	is_map_valid(t_game *g)
{
	int		y;
	int		x;
	size_t	len;
	size_t	first_len;

	if (g->rows == 0)
		return (0);
	first_len = 0;
	first_len = ft_strlen(g->map[0]);
	y = -1;
	while (++y < g->rows)
	{
		len = ft_strlen(g->map[y]);
		if (len != first_len)
			return (0);
		x = -1;
		while (++x < g->cols)
			if (g->map[y][x] != '0' && g->map[y][x] != '1' &&
				g->map[y][x] != 'C' && g->map[y][x] != 'E' &&
				g->map[y][x] != 'P' && g->map[y][x] != 'X')
				return (0);
	}
	return (1);
}

int	is_map_surrounded(t_game *g)
{
	int	y;
	int	x;

	y = -1;
	while (++y < g->rows)
	{
		x = -1;
		while (++x < g->cols)
		{
			if ((y == 0 || y == g->rows - 1 || x == 0 || x == g->cols - 1)
				&& g->map[y][x] != '1')
				return (0);
		}
	}
	return (1);
}

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

void	display_moves(t_game *game)
{
	char	*moves;
	char	*moves_str;

	moves = ft_itoa(game->moves);
	if (!moves)
		return ;
	moves_str = ft_strjoin("Moves: ", moves);
	free(moves);
	if (!moves_str)
		return ;
	mlx_string_put(game->mlx, game->win, 10, 20, 0xFFFFFF, moves_str);
	free(moves_str);
}
