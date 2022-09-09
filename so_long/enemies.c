/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:35:57 by daparici          #+#    #+#             */
/*   Updated: 2022/09/09 18:27:50 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_enemy_frame(int frame, t_map *map, char *image)
{
	if (map->frames_enemies == frame)
	{
		put_imagen_xpm(map, "./sprites/suelo_ok.xpm",
			map->enemy_y, map->enemy_x);
		put_imagen_xpm(map, image, map->enemy_y, map->enemy_x);
	}
}

int	move_enemies_identify(t_map *map, int i, int k)
{
	if (map->split_map[i][k] == 'T' && map->enemies_copy == 0)
	{
		map->split_map[i][k] = 't';
		map->enemy_x = k;
		map->enemy_y = i;
		map->copy_n_enemies--;
		if (map->copy_n_enemies == 0 && map->enemies_copy == 0)
			map->enemies_copy = 1;
		return (1);
	}
	if (map->split_map[i][k] == 't' && map->enemies_copy == 1)
	{
		map->split_map[i][k] = 'T';
		map->enemy_x = k;
		map->enemy_y = i;
		map->copy_n_enemies--;
		if (map->copy_n_enemies == 0 && map->enemies_copy == 1)
			map->enemies_copy = 0;
		return (1);
	}
	return (0);
}

void	move_enemies_params(t_map *map)
{
	if (map->copy_n_enemies == 0)
		map->copy_n_enemies = map->n_enemies;
	if (map->frames_enemies == 9)
	{
		map->copy_px = map->px;
		map->copy_py = map->py;
		map->copy_enemy_x = map->enemy_x;
		map->copy_enemy_y = map->enemy_y;
		map->move_enemy_x = map->copy_enemy_x - map->copy_px;
		if (map->move_enemy_x < 0)
			map->move_enemy_x *= -1;
		map->move_enemy_y = map->copy_enemy_y - map->copy_py;
		if (map->move_enemy_y < 0)
			map->move_enemy_y *= -1;
	}
	if (map->move_enemy_y >= map->move_enemy_x)
		move_enemy_y(map);
	if (map->move_enemy_x > map->move_enemy_y)
		move_enemy_x(map);
	if (map->frames_enemies == 2402)
		map->frames_enemies = 0;
}

void	move_enemies(t_map *map)
{
	int	i;
	int	k;

	i = -1;
	while (map->split_map[++i] && map->frames_enemies == 1)
	{
		k = -1;
		while (map->split_map[i][++k])
		{
			if (move_enemies_identify(map, i, k))
				break ;
		}
		if (map->split_map[i][k] == 'T' || map->split_map[i][k] == 't')
			break ;
	}
	move_enemies_params(map);
}

void	move_enemy_y(t_map *map)
{
	move_enemy_frame(10, map, "./sprites/bubu_right2.xpm");
	move_enemy_frame(400, map, "./sprites/bubu_move_y.xpm");
	move_enemy_frame(800, map, "./sprites/bubu_move_y2.xpm");
	move_enemy_frame(1200, map, "./sprites/bubu_move_y3.xpm");
	move_enemy_frame(1600, map, "./sprites/bubu_move_y4.xpm");
	if (map->frames_enemies == 2000 && map->copy_py < map->copy_enemy_y)
		move_enemy_y_up(map);
	if (map->frames_enemies == 2000 && map->copy_py > map->copy_enemy_y)
		move_enemy_y_down(map);
}
