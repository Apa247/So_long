/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:20:10 by daparici          #+#    #+#             */
/*   Updated: 2022/09/09 18:26:29 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_enemy_y_down(t_map *map)
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
		put_imagen_xpm(map, "./sprites/suelo_ok.xpm",
			map->enemy_y, map->enemy_x);
		map->enemy_y++;
		if (map->px == map->enemy_x && map->py == map->enemy_y)
			closewin(map);
		if (map->enemy_dir_x == 0)
			move_enemy_frame(2000, map, "./sprites/bubu_right.xpm");
		else
			move_enemy_frame(2000, map, "./sprites/bubu_left.xpm");
		map->split_map[map->enemy_y][map->enemy_x]
			= map->split_map[map->enemy_y - 1][map->enemy_x];
		map->split_map[map->enemy_y - 1][map->enemy_x] = '0';
	}
	else
		move_enemy_frame(2000, map, "./sprites/bubu_right.xpm");
	map->frames_enemies = 0;
}

void	move_enemy_y_up(t_map *map)
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
		put_imagen_xpm(map, "./sprites/suelo_ok.xpm",
			map->enemy_y, map->enemy_x);
		map->enemy_y--;
		if (map->px == map->enemy_x && map->py == map->enemy_y)
			closewin(map);
		if (map->enemy_dir_x == 0)
			move_enemy_frame(2000, map, "./sprites/bubu_right.xpm");
		else
			move_enemy_frame(2000, map, "./sprites/bubu_left.xpm");
		map->split_map[map->enemy_y][map->enemy_x]
			= map->split_map[map->enemy_y + 1][map->enemy_x];
		map->split_map[map->enemy_y + 1][map->enemy_x] = '0';
	}
	else
		move_enemy_frame(2000, map, "./sprites/bubu_right.xpm");
		map->frames_enemies = 0;
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
			move_enemy_x_right(map);
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
			move_enemy_x_left(map);
		move_enemy_frame(2000, map, "./sprites/bubu_move_x2_left.xpm");
		move_enemy_frame(2400, map, "./sprites/bubu_left.xpm");
	}
}

void	move_enemy_x_right(t_map *map)
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
		put_imagen_xpm(map, "./sprites/suelo_ok.xpm",
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

void	move_enemy_x_left(t_map *map)
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
		put_imagen_xpm(map, "./sprites/suelo_ok.xpm",
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
