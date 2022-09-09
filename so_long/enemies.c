/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:35:57 by daparici          #+#    #+#             */
/*   Updated: 2022/09/09 15:31:42 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_enemy_frame(int frame, t_map *map, char *image)
{
	if (map->frames_enemies == frame)
	{
		put_imagen_xpm(map, "./sprites/suelo.xpm", map->enemy_y, map->enemy_x);
		put_imagen_xpm(map, image, map->enemy_y, map->enemy_x);
	}
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
			if (map->split_map[i][k] == 'T' && map->enemies_copy == 0)
			{
				map->split_map[i][k] = 't';
				map->enemy_x = k;
				map->enemy_y = i;
				map->copy_n_enemies--;
				if (map->copy_n_enemies == 0 && map->enemies_copy == 0)
					map->enemies_copy = 1;
				break ;
			}
			if (map->split_map[i][k] == 't' && map->enemies_copy == 1)
			{
				map->split_map[i][k] = 'T';
				map->enemy_x = k;
				map->enemy_y = i;
				map->copy_n_enemies--;
				if (map->copy_n_enemies == 0 && map->enemies_copy == 1)
					map->enemies_copy = 0;
				break ;
			}
		}
		if (map->split_map[i][k] == 'T' || map->split_map[i][k] == 't')
			break ;
	}
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

void	move_enemy_y(t_map *map)
{
	move_enemy_frame(10, map, "./sprites/bubu_right2.xpm");
	move_enemy_frame(400, map, "./sprites/bubu_move_y.xpm");
	move_enemy_frame(800, map, "./sprites/bubu_move_y2.xpm");
	move_enemy_frame(1200, map, "./sprites/bubu_move_y3.xpm");
	move_enemy_frame(1600, map, "./sprites/bubu_move_y4.xpm");
	if (map->frames_enemies == 2000 && map->copy_py < map->copy_enemy_y)
	{
		if (map->split_map[map->enemy_y - 1][map->enemy_x] == 'P')
			closewin(map);
		if (map->split_map[map->enemy_y - 1][map->enemy_x] != '1' &&
			map->split_map[map->enemy_y - 1][map->enemy_x] != 'C' &&
			map->split_map[map->enemy_y - 1][map->enemy_x] != 'E' &&
			map->split_map[map->enemy_y - 1][map->enemy_x] != 'O' &&
			map->split_map[map->enemy_y - 1][map->enemy_x] != 'T' &&
			map->split_map[map->enemy_y - 1][map->enemy_x] != 't')
		{
			put_imagen_xpm(map, "./sprites/suelo.xpm",
				map->enemy_y, map->enemy_x);
			map->enemy_y--;
			if (map->enemy_dir_x == 0)
				move_enemy_frame(2000, map, "./sprites/bubu_right.xpm");
			else
				move_enemy_frame(2000, map, "./sprites/bubu_left.xpm");
			map->split_map[map->enemy_y][map->enemy_x]
				= map->split_map[map->enemy_y + 1][map->enemy_x];
			map->split_map[map->enemy_y + 1][map->enemy_x] = '0';
		}
		else
		{
			move_enemy_frame(2000, map, "./sprites/bubu_right.xpm");
			//map->enemy_dir_y = 0;
		}
		map->frames_enemies = 0;
	}
	if (map->frames_enemies == 2000 && map->copy_py > map->copy_enemy_y)
	{
		if (map->split_map[map->enemy_y + 1][map->enemy_x] == 'P')
			closewin(map);
		if (map->split_map[map->enemy_y + 1][map->enemy_x] != '1' &&
			map->split_map[map->enemy_y + 1][map->enemy_x] != 'C' &&
			map->split_map[map->enemy_y + 1][map->enemy_x] != 'E' &&
			map->split_map[map->enemy_y + 1][map->enemy_x] != 'O' &&
			map->split_map[map->enemy_y + 1][map->enemy_x] != 'T' &&
			map->split_map[map->enemy_y + 1][map->enemy_x] != 't')
		{
			put_imagen_xpm(map, "./sprites/suelo.xpm",
				map->enemy_y, map->enemy_x);
			map->enemy_y++;
			if (map->enemy_dir_x == 0)
				move_enemy_frame(2000, map, "./sprites/bubu_right.xpm");
			else
				move_enemy_frame(2000, map, "./sprites/bubu_left.xpm");
			map->split_map[map->enemy_y][map->enemy_x]
				= map->split_map[map->enemy_y - 1][map->enemy_x];
			map->split_map[map->enemy_y - 1][map->enemy_x] = '0';
		}
		else
		{
			move_enemy_frame(2000, map, "./sprites/bubu_right.xpm");
			//map->enemy_dir_y = 1;
		}
		map->frames_enemies = 0;
	}
}

void	move_enemy_x(t_map *map)
{
	if (map->copy_px > map->copy_enemy_x)
	{
		move_enemy_frame(10, map, "./sprites/bubu_move_x.xpm");
		move_enemy_frame(400, map, "./sprites/bubu_move_x2.xpm");
		move_enemy_frame(800, map, "./sprites/bubu_move_x3.xpm");
		move_enemy_frame(1200, map, "./sprites/bubu_move_x4.xpm");
		if (map->frames_enemies == 1600)
		{
			if (map->split_map[map->enemy_y][map->enemy_x + 1] == 'P')
				closewin(map);
			if (map->split_map[map->enemy_y][map->enemy_x + 1] != '1' &&
			map->split_map[map->enemy_y][map->enemy_x + 1] != 'C' &&
			map->split_map[map->enemy_y][map->enemy_x + 1] != 'E' &&
			map->split_map[map->enemy_y][map->enemy_x + 1] != 'O' &&
			map->split_map[map->enemy_y][map->enemy_x + 1] != 'T' &&
			map->split_map[map->enemy_y][map->enemy_x + 1] != 't')
			{
				put_imagen_xpm(map, "./sprites/suelo.xpm",
					map->enemy_y, map->enemy_x);
				map->enemy_x++;
				map->split_map[map->enemy_y][map->enemy_x]
					= map->split_map[map->enemy_y][map->enemy_x - 1];
				map->split_map[map->enemy_y][map->enemy_x - 1] = '0';
				move_enemy_frame(1600, map, "./sprites/bubu_move_x5.xpm");
			}
			else
			{
				move_enemy_frame(1600, map, "./sprites/bubu_left.xpm");
				map->enemy_dir_x = 1;
				map->frames_enemies = 0;
			}
		}
		move_enemy_frame(2000, map, "./sprites/bubu_move_x2.xpm");
		move_enemy_frame(2400, map, "./sprites/bubu_right.xpm");
	}
	else if (map->copy_px < map->copy_enemy_x)
	{
		move_enemy_frame(10, map, "./sprites/bubu_move_x_left.xpm");
		move_enemy_frame(400, map, "./sprites/bubu_move_x2_left.xpm");
		move_enemy_frame(800, map, "./sprites/bubu_move_x3_left.xpm");
		move_enemy_frame(1200, map, "./sprites/bubu_move_x4_left.xpm");
		if (map->frames_enemies == 1600)
		{
			if (map->split_map[map->enemy_y][map->enemy_x - 1] == 'P')
				closewin(map);
			if (map->split_map[map->enemy_y][map->enemy_x - 1] != '1' &&
			map->split_map[map->enemy_y][map->enemy_x - 1] != 'C' &&
			map->split_map[map->enemy_y][map->enemy_x - 1] != 'E' &&
			map->split_map[map->enemy_y][map->enemy_x - 1] != 'O' &&
			map->split_map[map->enemy_y][map->enemy_x - 1] != 'T' &&
			map->split_map[map->enemy_y][map->enemy_x - 1] != 't')
			{
				put_imagen_xpm(map, "./sprites/suelo.xpm",
					map->enemy_y, map->enemy_x);
				map->enemy_x--;
				move_enemy_frame(1600, map, "./sprites/bubu_move_x5_left.xpm");
				map->split_map[map->enemy_y][map->enemy_x]
					= map->split_map[map->enemy_y][map->enemy_x + 1];
				map->split_map[map->enemy_y][map->enemy_x + 1] = '0';
			}
			else
			{
				move_enemy_frame(1600, map, "./sprites/bubu_right.xpm");
				map->enemy_dir_x = 0;
				map->frames_enemies = 0;
			}
		}
		move_enemy_frame(2000, map, "./sprites/bubu_move_x2_left.xpm");
		move_enemy_frame(2400, map, "./sprites/bubu_left.xpm");
	}
}
