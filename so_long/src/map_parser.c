/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:12:10 by jilin             #+#    #+#             */
/*   Updated: 2025/03/04 00:21:23 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P');
}

static int is_map_rectangular(t_game *game)
{
	int y;

	y = 0;
	while (y < game->rows)
	{
		if (ft_strlen(game->map[y]) != game->cols)
			return (0);
		y++;
	}
	return (1);
}

static void	count_elements(t_game *game, int *p_count, int *e_count, int *c_count)
{
	int y;
	int x;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols)
		{
			char c = game->map[y][x];
			if (c == 'P')
			{
				(*p_count)++;
				game->player_x = x;
				game->player_y = y;
			}
			else if (c == 'E')
				(*e_count)++;
			else if (c == 'C')
				(*c_count)++;
			x++;
		}
		y++;
	}
}

static int is_map_surrounded_by_walls(t_game *game)
{
	int y;
	int x;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols)
		{
			char c = game->map[y][x];
			if ((y == 0 || y == game->rows - 1 || x == 0 || x == game->cols - 1)
				&& c != '1')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	validate_map(t_game *game)
{
	int p_count;
	int e_count;
	int c_count;

	p_count = 0;
	e_count = 0;
	c_count = 0;
	if (!is_map_rectangular(game))
		return (0);
	count_elements(game, &p_count, &e_count, &c_count);
	if (!is_map_surrounded_by_walls(game))
		return (0);
	game->collectibles = c_count;
	game->collected = 0;
	return (p_count == 1 && e_count == 1 && c_count > 0);
}

int parse_map(t_game *game, char *file)
{
	int fd;
	char *line;
	int y;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	game->rows = 0;
	while (get_next_line(fd) != NULL)
		game->rows++;
	close(fd);
	
	game->map = malloc(sizeof(char *)* (game->rows + 1));
	if (!game->map)
		return (0);

	fd = open(fille, O_RDONLY);
	y = 0;
	while ((line = get_next_line(fd)) != NULL)
		game->map[y++] = line;
	game->map[y] = NULL;
	close(fd);

	game->cols = ft_strlen(game->map[0]);	
	return (validate_map(game));
}
