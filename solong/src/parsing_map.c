/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:41:00 by jilin             #+#    #+#             */
/*   Updated: 2025/03/14 20:34:03 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	count_element(t_game *g, char c, int *count)
{
	int	y;
	int	x;

	y = -1;
	*count = 0;
	while (++y < g->rows)
	{
		x = -1;
		while (++x < g->cols)
		{
			if (g->map[y][x] == 'P')
			{
				g->player_x = x;
				g->player_y = y;
			}
			if (g->map[y][x] == c)
				(*count)++;
		}
	}
}

static int	count_line(t_game *g, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	g->rows = 0;
	line = get_next_line(fd);
	while (line)
	{
		g->rows++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

static int	fill_map(t_game *g, char *file)
{
	int		fd;
	char	*line;
	int		y;
	size_t	len;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	y = -1;
	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		g->map[++y] = line;
		detect_enemies(g, line, y);
		line = get_next_line(fd);
	}
	g->map[++y] = NULL;
	close(fd);
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
		return (ft_printf("Error\nInvalid characters\n"), 0);
	if (!is_map_rectangular(g))
		return (ft_printf("Error\nMap not rectangular\n"), 0);
	count_element(g, 'P', &p);
	count_element(g, 'E', &e);
	count_element(g, 'C', &c);
	g->collectibles = c;
	if (!is_map_surrounded(g))
		return (ft_printf("Error\nMissing walls\n"), 0);
	if (p != 1 || e != 1 || c < 1)
		return (ft_printf("Error\nInvalid P/E/C count\n"), 0);
	if (!is_path_valid(g))
		return (ft_printf("Error\nUnreachable elements\n"), 0);
	return (1);
}

int	parse_map(t_game *g, char *file)
{
	if (!count_line(g, file))
		return (0);
	g->map = malloc(sizeof(char *) * (g->rows + 1));
	if (!g->map)
		return (0);
	if (!fill_map(g, file))
	{
		free_map(g->map, g->rows);
		return (0);
	}
	g->cols = ft_strlen(g->map[0]);
	if (!validate_map(g))
	{
		free_map(g->map, g->rows);
		g->map = NULL;
		return (0);
	}
	return (1);
}
