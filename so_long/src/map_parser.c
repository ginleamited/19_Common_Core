#include "../inc/so_long.h"

static int is_map_characters(t_game *game)
{
    int y, x;
    char c;

    y = 0;
    while (y < game->rows)
    {
        x = 0;
        while (x < game->cols)
        {
            c = game->map[y][x];
            if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
                return (0);
            x++;
        }
        y++;
    }
    return (1);
}

static int is_map_rectangular(t_game *game)
{
    int y;
    size_t len;

    if (game->rows == 0)
        return (0);
    len = ft_strlen(game->map[0]);
    y = 1;
    while (y < game->rows)
    {
        if (ft_strlen(game->map[y]) != len)
            return (0);
        y++;
    }
    return (1);
}

static void count_elements(t_game *game, int *p_count, int *e_count, int *c_count)
{
    int y, x;

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
    int y, x;

    y = 0;
    while (y < game->rows)
    {
        x = 0;
        while (x < game->cols)
        {
            char c = game->map[y][x];
            if ((y == 0 || y == game->rows - 1 || x == 0 || x == game->cols - 1) && c != '1')
                return (0);
            x++;
        }
        y++;
    }
    return (1);
}

static int is_path_valid(t_game *game)
{
    int **visited;
    int changed;
    int i, j;
    int reachable_c = 0;
    int e_reachable = 0;
    int total_c = game->collectibles;

    visited = malloc(sizeof(int *) * game->rows);
    for (i = 0; i < game->rows; i++)
    {
        visited[i] = malloc(sizeof(int) * game->cols);
        for (j = 0; j < game->cols; j++)
            visited[i][j] = 0;
    }

    visited[game->player_y][game->player_x] = 1;

    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};

    do {
        changed = 0;
        for (i = 0; i < game->rows; i++)
        {
            for (j = 0; j < game->cols; j++)
            {
                if (visited[i][j])
                {
                    for (int d = 0; d < 4; d++)
                    {
                        int new_x = j + dx[d];
                        int new_y = i + dy[d];
                        if (new_x >= 0 && new_x < game->cols && new_y >= 0 && new_y < game->rows)
                        {
                            char tile = game->map[new_y][new_x];
                            if (!visited[new_y][new_x] && (tile == '0' || tile == 'C' || tile == 'E' || tile == 'P'))
                            {
                                visited[new_y][new_x] = 1;
                                changed = 1;
                            }
                        }
                    }
                }
            }
        }
    } while (changed);

    for (i = 0; i < game->rows; i++)
    {
        for (j = 0; j < game->cols; j++)
        {
            if (visited[i][j])
            {
                if (game->map[i][j] == 'C')
                    reachable_c++;
                if (game->map[i][j] == 'E')
                    e_reachable = 1;
            }
        }
    }

    for (i = 0; i < game->rows; i++)
        free(visited[i]);
    free(visited);

    return (reachable_c == total_c && e_reachable);
}

int validate_map(t_game *game)
{
    int p_count = 0, e_count = 0, c_count = 0;

    if (!is_map_characters(game))
        return (ft_printf("Invalid characters\n"), 0);
    if (!is_map_rectangular(game)) 
        return (ft_printf("Map not rectangular\n"), 0);
    
    count_elements(game, &p_count, &e_count, &c_count);
    
    game->collectibles = c_count;

    if (!is_map_surrounded_by_walls(game)) 
        return (ft_printf("Walls missing\n"), 0);
    if (p_count != 1 || e_count != 1 || c_count < 1) 
        return (ft_printf("Invalid P/E/C count\n"), 0);
    if (!is_path_valid(game))
        return (ft_printf("P, E, or C enclosed by walls\n"), 0);
    
    return (1);
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
    char *tmp_line;
    while ((tmp_line = get_next_line(fd)) != NULL)
    {
        game->rows++;
        free(tmp_line);
    }
    close(fd);

    game->map = malloc(sizeof(char *) * (game->rows + 1));
    if (!game->map)
        return (0);

    fd = open(file, O_RDONLY);
    y = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        size_t len = ft_strlen(line);
        if (len > 0 && line[len - 1] == '\n')
            line[len - 1] = '\0';
        game->map[y++] = line;
    }
    game->map[y] = NULL;
    close(fd);

    game->cols = ft_strlen(game->map[0]);

    if (!validate_map(game))
    {
        free_map(game->map, game->rows);
        game->map = NULL;
        return (0);
    }

    return (1);
}
