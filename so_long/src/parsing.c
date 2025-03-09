#include "../inc/so_long.h"

static int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P');
}

static int	is_map_characters(t_game *g)
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

static int	is_map_rectangular(t_game *g)
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

static int	is_map_surrounded(t_game *g)
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

static int	count_rows(t_game *g, char *file)
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
		line = get_next_line(fd);
	}
	g->map[++y] = NULL;
	close(fd);
	return (1);
}

int	parse_map(t_game *g, char *file)
{
	if (!count_rows(g, file))
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
