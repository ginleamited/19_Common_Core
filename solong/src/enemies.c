/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 20:03:31 by jilin             #+#    #+#             */
/*   Updated: 2025/03/13 22:22:35 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void render_enemies(t_game *game)
{
    t_enemy *enemy = game->enemies;
    while (enemy)
    {
        mlx_put_image_to_window(game->mlx, game->win, game->enemy_img,
                                enemy->x * TILE_SIZE, enemy->y * TILE_SIZE);
        enemy = enemy->next;
    }
}

void add_enemy(t_game *game, int x, int y)
{
	t_enemy	*new_enemy;

	new_enemy = malloc(sizeof(t_enemy));
	if (!new_enemy)
		return;
	new_enemy->x = x;
	new_enemy->y = y;
	new_enemy->next = game->enemies;
	game->enemies = new_enemy;
}

void	detect_enemies(t_game *g, char *line, int y)
{
	int	x;

	x = -1;
	while (line[++x])
	{
		if (line[x] == 'X')
			add_enemy(g, x, y);
	}
}

void free_enemies(t_enemy *enemies)
{
    t_enemy *temp;

    while (enemies)
    {
        temp = enemies;
        enemies = enemies->next;
        free(temp);
    }
}
