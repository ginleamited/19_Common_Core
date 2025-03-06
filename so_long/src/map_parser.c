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
        while (x < game->cols) // Use game->cols here
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

int validate_map(t_game *game)
{
    int p_count = 0, e_count = 0, c_count = 0;

    if (!is_map_characters(game))
        return (ft_printf("Invalid characters\n"), 0);
    if (!is_map_rectangular(game)) 
        return (ft_printf("Map not rectangular\n"), 0);
    
    count_elements(game, &p_count, &e_count, &c_count);
    
    // Assign collectibles count to the game struct
    game->collectibles = c_count; // <-- CRITICAL FIX

    if (!is_map_surrounded_by_walls(game)) 
        return (ft_printf("Walls missing\n"), 0);
    if (p_count != 1 || e_count != 1 || c_count < 1) 
        return (ft_printf("Invalid P/E/C count\n"), 0);
    
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

    // Count rows and free lines
    game->rows = 0;
    char *tmp_line;
    while ((tmp_line = get_next_line(fd)) != NULL)
    {
        game->rows++;
        free(tmp_line);
    }
    close(fd);

    // Allocate map memory
    game->map = malloc(sizeof(char *) * (game->rows + 1));
    if (!game->map)
        return (0);

    // Read and trim lines
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

    // Initialize columns
    game->cols = ft_strlen(game->map[0]); // <-- Critical fix

    // Validate map
    if (!validate_map(game))
    {
        free_map(game->map, game->rows);
        game->map = NULL;
        return (0);
    }

    return (1);
}
