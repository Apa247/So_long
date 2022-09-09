/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_supergoku.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:35:57 by daparici          #+#    #+#             */
/*   Updated: 2022/08/14 19:20:44 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_supergoku_y(t_map *map)
{
	if (map->n_frames == 0)
	{
		put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
		if (map->pl_dir == 0)
			put_imagen_xpm(map, "./sprites/supergoku_move_y.xpm",
				map->py, map->px);
		else
			put_imagen_xpm(map, "./sprites/supergoku_move_y_left.xpm",
				map->py, map->px);
	}
	if (map->n_frames == 400)
	{
		put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
		if (map->pl_dir == 0)
			put_imagen_xpm(map, "./sprites/supergoku_move_y2.xpm",
				map->py, map->px);
		else
			put_imagen_xpm(map, "./sprites/supergoku_move_y2_left.xpm",
				map->py, map->px);
	}
	move_frame(800, map, "./sprites/goku_move_y_bueno.xpm");
	if (map->n_frames == 1200)
	{
		put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
		map->split_map[map->py][map->px] = '0';
		put_goku_map(map);
	}
}

void	put_supergoku_map_y(t_map *map)
{
	if (map->keycode_c == 13)
	{
		map->py--;
		if (map->split_map[map->py][map->px] == 'C')
			map->ki = 1;
		map->split_map[map->py][map->px] = 'P';
		if (map->pl_dir == 0)
			move_frame(1200, map, "./sprites/supergoku_right.xpm");
		else
			move_frame(1200, map, "./sprites/supergoku_left.xpm");
	}
	if (map->keycode_c == 1)
	{
		map->py++;
		if (map->split_map[map->py][map->px] == 'C')
			map->ki = 1;
		map->split_map[map->py][map->px] = 'P';
		if (map->pl_dir == 0)
			move_frame(1200, map, "./sprites/supergoku_right.xpm");
		else
			move_frame(1200, map, "./sprites/supergoku_left.xpm");
	}
}

void	move_supergoku_x_left(t_map *map)
{
	if (map->n_frames == 100)
		move_frame(100, map, "./sprites/supergoku_move_x_left.xpm");
	if (map->n_frames == 800)
	{
		put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
		map->split_map[map->py][map->px] = '0';
		put_goku_map(map);
	}
	if (map->n_frames == 1300)
		put_goku_map(map);
}

void	move_supergoku_x_right(t_map *map)
{
	if (map->n_frames == 100)
		move_frame(100, map, "./sprites/supergoku_move_x.xpm");
	if (map->n_frames == 800)
	{
		put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
		map->split_map[map->py][map->px] = '0';
		put_goku_map(map);
	}
	if (map->n_frames == 1300)
		put_goku_map(map);
}

void	put_supergoku_map_x(t_map *map)
{
	if (map->keycode_c == 0 && map->n_frames == 800)
	{
		map->px--;
		put_imagen_xpm(map, "./sprites/supergoku_move_x2_left.xpm",
			map->py, map->px);
	}
	if (map->keycode_c == 0 && map->n_frames == 1300)
	{
		if (map->split_map[map->py][map->px] == 'C')
			map->ki = 1;
		map->split_map[map->py][map->px] = 'P';
		move_frame(1300, map, "./sprites/supergoku_left.xpm");
	}
	if (map->keycode_c == 2 && map->n_frames == 800)
	{
		map->px++;
		put_imagen_xpm(map, "./sprites/supergoku_move_x2.xpm",
			map->py, map->px);
	}
	if (map->keycode_c == 2 && map->n_frames == 1300)
	{
		if (map->split_map[map->py][map->px] == 'C')
			map->ki = 1;
		map->split_map[map->py][map->px] = 'P';
		move_frame(1300, map, "./sprites/supergoku_right.xpm");
	}
}
