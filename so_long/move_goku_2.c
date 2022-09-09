/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_goku_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:35:57 by daparici          #+#    #+#             */
/*   Updated: 2022/09/09 13:59:11 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_goku_map(t_map *map)
{
	if (map->supergoku == 0 && (map->keycode_c == 13
			|| map->keycode_c == 1))
		put_goku_map_y(map);
	if (map->supergoku == 1 && (map->keycode_c == 13
			|| map->keycode_c == 1))
		put_supergoku_map_y(map);
	if (map->supergoku == 0 && (map->keycode_c == 0
			|| map->keycode_c == 2))
		put_goku_map_x(map);
	if (map->supergoku == 1 && (map->keycode_c == 0
			|| map->keycode_c == 2))
		put_supergoku_map_x(map);
}

void	put_goku_map_x(t_map *map)
{
	if (map->keycode_c == 0 && map->n_frames == 800)
	{
		map->px--;
		if (map->split_map[map->py][map->px] == 'C')
			map->ki = 1;
		map->split_map[map->py][map->px] = 'P';
		put_imagen_xpm(map, "./sprites/goku_move_left3.xpm", map->py, map->px);
	}
	if (map->keycode_c == 0 && map->n_frames == 1300)
		move_frame(1300, map, "./sprites/goku_left.xpm");
	if (map->keycode_c == 2 && map->n_frames == 800)
	{
		map->px++;
		if (map->split_map[map->py][map->px] == 'C')
			map->ki = 1;
		map->split_map[map->py][map->px] = 'P';
		put_imagen_xpm(map, "./sprites/goku_move_left.xpm", map->py, map->px);
	}
	if (map->keycode_c == 2 && map->n_frames == 1300)
		move_frame(1300, map, "./sprites/goku_buena.xpm");
}

void	put_goku_map_y(t_map *map)
{
	if (map->keycode_c == 13)
	{
		map->py--;
		if (map->split_map[map->py][map->px] == 'C')
			map->ki = 1;
		map->split_map[map->py][map->px] = 'P';
		if (map->pl_dir == 0)
			move_frame(1200, map, "./sprites/goku_buena.xpm");
		else
			move_frame(1200, map, "./sprites/goku_left.xpm");
	}
	if (map->keycode_c == 1)
	{
		map->py++;
		if (map->split_map[map->py][map->px] == 'C')
			map->ki = 1;
		map->split_map[map->py][map->px] = 'P';
		if (map->pl_dir == 0)
			move_frame(1200, map, "./sprites/goku_buena.xpm");
		else
			move_frame(1200, map, "./sprites/goku_left.xpm");
	}
}
