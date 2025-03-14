/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:40:54 by jilin             #+#    #+#             */
/*   Updated: 2025/03/14 01:59:54 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'E' ||
			c == 'P' || c == 'X');
}

int	is_map_characters(t_game *g)
{
	int	y;
	int	x;

	y = -1;
	while (++y < g->rows)
	{
		x = -1;
		while (++x < g->cols)
			if (!is_valid_char(g->map[y][x]))
				return (0);
	}
	return (1);
}

int	is_map_rectangular(t_game *g)
{
	size_t	len;
	int		y;

	if (g->rows == 0)
		return (0);
	len = ft_strlen(g->map[0]);
	y = 0;
	while (++y < g->rows)
		if ((size_t)ft_strlen(g->map[y]) != len)
			return (0);
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
