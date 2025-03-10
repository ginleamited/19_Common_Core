/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 22:10:38 by jilin             #+#    #+#             */
/*   Updated: 2025/03/09 22:13:31 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P');
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
