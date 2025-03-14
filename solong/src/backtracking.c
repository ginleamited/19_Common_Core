/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:41:23 by jilin             #+#    #+#             */
/*   Updated: 2025/03/14 02:56:21 by jilin            ###   ########.fr       */
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


int	validate_map(t_game *g)
{
	int	p;
	int	e;
	int	c;

	p = 0;
	e = 0;
	c = 0;
	if (!is_map_characters(g))
		return (ft_printf("Error\nInvalid characters in map\n"), 0);
	if (!is_map_rectangular(g))
		return (ft_printf("Error\nMap is not rectangular\n"), 0);
	count_element(g, 'P', &p);
	count_element(g, 'E', &e);
	count_element(g, 'C', &c);
	g->collectibles = c;
	if (!is_map_surrounded(g))
		return (ft_printf("Error\nMap must be fully surrounded by walls\n"), 0);
	if (p != 1 || e != 1 || c < 1)
		return (ft_printf("Error\nInvalid number of P, E, or C\n"), 0);
	if (!is_path_valid(g))
		return (ft_printf("Error\nPlayer cannot reach all collectibles or exit\n"), 0);
	return (1);
}

