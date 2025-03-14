/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:41:23 by jilin             #+#    #+#             */
/*   Updated: 2025/03/14 03:07:33 by jilin            ###   ########.fr       */
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
		|| v[y][x] || g->map[y][x] == '1' || g->map[y][x] == 'X')
		return ;
	v[y][x] = 1;
	ft_printf("Visiting: (%d, %d) -> %c\n", y, x, g->map[y][x]);
	dfs(g, v, y - 1, x);
	dfs(g, v, y + 1, x);
	dfs(g, v, y, x - 1);
	dfs(g, v, y, x + 1);
}

static int	check_reach(t_game *g, int **v)
{
	int	i;
	int	j;
	int	collected_count;
	int	exit_reached;
	int	total_collectibles = 0;

	collected_count = 0;
	exit_reached = 0;
	i = -1;
	while (++i < g->rows)
	{
		j = -1;
		while (++j < g->cols)
		{
			if (g->map[i][j] == 'C')
				total_collectibles++;
			if (v[i][j])
			{
				collected_count += (g->map[i][j] == 'C');
				exit_reached |= (g->map[i][j] == 'E');
			}
		}
	}
	if (collected_count != total_collectibles || !exit_reached)
	{
		ft_printf("Error: Some collectibles or exit are unreachable!\n");
		return (0);
	}
	return (1);
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
