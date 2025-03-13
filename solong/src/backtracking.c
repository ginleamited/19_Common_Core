/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:41:23 by jilin             #+#    #+#             */
/*   Updated: 2025/03/11 19:41:25 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	**init_visited(t_game *g)
{
	int	**v;
	int	i;
	int	j;

	v = malloc(sizeof(int *) * g->rows);
	if (!v)
		return (NULL);
	i = -1;
	while (++i < g->rows)
	{
		v[i] = malloc(sizeof(int) * g->cols);
		if (!v[i])
			return (NULL);
		j = -1;
		while (++j < g->cols)
			v[i][j] = 0;
	}
	return (v);
}

static void	dfs(t_game *g, int **v, int y, int x)
{
	if (y < 0 || x < 0 || y >= g->rows || x >= g->cols
		|| v[y][x] || g->map[y][x] == '1')
		return ;
	v[y][x] = 1;
	dfs(g, v, y - 1, x);
	dfs(g, v, y + 1, x);
	dfs(g, v, y, x - 1);
	dfs(g, v, y, x + 1);
}

static int	check_reach(t_game *g, int **v)
{
	int	i;
	int	j;
	int	c;
	int	e;

	c = 0;
	e = 0;
	i = -1;
	while (++i < g->rows)
	{
		j = -1;
		while (++j < g->cols)
		{
			if (v[i][j])
			{
				c += (g->map[i][j] == 'C');
				e |= (g->map[i][j] == 'E');
			}
		}
	}
	return (c == g->collectibles && e);
}

int	is_path_valid(t_game *g)
{
	int	**v;
	int	res;

	v = init_visited(g);
	if (!v)
		return (0);
	dfs(g, v, g->player_y, g->player_x);
	res = check_reach(g, v);
	free_2d_array((void **)v, g->rows);
	return (res);
}
