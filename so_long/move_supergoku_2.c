/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_supergoku_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:38:31 by daparici          #+#    #+#             */
/*   Updated: 2022/09/12 13:39:25 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_supergoku_x_left(t_map *map)
{
	if (map->n_frames == 100)
		move_frame(100, map, "./sprites/supergoku_move_x_left.xpm");
	if (map->n_frames == 800)
	{
		put_imagen_xpm(map, "./sprites/suelo_ok.xpm", map->py, map->px);
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
		put_imagen_xpm(map, "./sprites/suelo_ok.xpm", map->py, map->px);
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
	put_supergoku_map_x2(map);
}

void	put_supergoku_map_x2(t_map *map)
{
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