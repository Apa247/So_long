/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_goku.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:35:57 by daparici          #+#    #+#             */
/*   Updated: 2022/08/06 21:09:38 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_goku_x(t_map *map)
{
	if (map->keycode_c == 0 && map->supergoku == 0)
		move_goku_x_left(map);
	if (map->keycode_c == 0 && map->supergoku == 1)
		move_supergoku_x_left(map);
	if (map->keycode_c == 2 && map->supergoku == 0)
		move_goku_x_right(map);
	if (map->keycode_c == 2 && map->supergoku == 1)
		move_supergoku_x_right(map);
}

void	move_goku_x_right(t_map *map)
{
	if (map->n_frames == 100)
		move_frame(100, map, "./sprites/goku_move_right.xpm");
	if (map->n_frames == 800)
	{
		put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
		map->split_map[map->py][map->px] = '0';
		put_goku_map(map);
	}
	if (map->n_frames == 1300)
		put_goku_map(map);
}

void	move_goku_x_left(t_map *map)
{
	if (map->n_frames == 0)
		move_frame(0, map, "./sprites/goku_move_y_left2.xpm");
	if (map->n_frames == 800)
	{
		put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
		map->split_map[map->py][map->px] = '0';
		put_goku_map(map);
	}
	if (map->n_frames == 1300)
		put_goku_map(map);
}

void	move_goku_y(t_map *map)
{
	if (map->n_frames == 0)
	{
		put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
		if (map->pl_dir == 0)
			put_imagen_xpm(map, "./sprites/goku_move_y.xpm",
				map->py, map->px);
		else
			put_imagen_xpm(map, "./sprites/goku_move_y_left.xpm",
				map->py, map->px);
	}
	if (map->n_frames == 400)
	{
		put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
		if (map->pl_dir == 0)
			put_imagen_xpm(map, "./sprites/goku_move_y_borroso.xpm",
				map->py, map->px);
		else
			put_imagen_xpm(map, "./sprites/goku_move_y_borroso2.xpm",
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
