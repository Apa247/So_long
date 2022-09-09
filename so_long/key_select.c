/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_select.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:37:52 by daparici          #+#    #+#             */
/*   Updated: 2022/09/09 18:11:58 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_x(int keycode, t_map *map, int *i)
{
	key_x_left(keycode, map, i);
	key_x_right(keycode, map, i);
}

void	key_x_right(int keycode, t_map *map, int *i)
{
	if (keycode == 2 && map->split_map[map->py][map->px + 1] != '1' &&
		map->split_map[map->py][map->px + 1] != 'E')
	{
		if (map->split_map[map->py][map->px + 1] == 'O' ||
			map->split_map[map->py][map->px + 1] == 'T' ||
			map->split_map[map->py][map->px + 1] == 't')
			closewin(map);
		if (map->pl_dir == 1)
		{
			if (map->supergoku == 0)
			{
				put_imagen_xpm(map, "./sprites/suelo_ok.xpm", map->py, map->px);
				put_imagen_xpm(map, "./sprites/goku_buena.xpm",
					map->py, map->px);
				map->pl_dir = 0;
			}
			else
			{
				put_imagen_xpm(map, "./sprites/suelo_ok.xpm", map->py, map->px);
				put_imagen_xpm(map, "./sprites/supergoku_right.xpm",
					map->py, map->px);
				map->pl_dir = 0;
			}
		}
		if (map->split_map[map->py][map->px + 1] == 'C')
		{
			map->n_collect -= 1;
			map->frame_exit = 0;
		}
		map->n_frames = 0;
		map->keycode_c = keycode;
		*i = 1;
	}
}

void	key_x_left(int keycode, t_map *map, int *i)
{
	if (keycode == 0 && map->split_map[map->py][map->px - 1] != '1' &&
		map->split_map[map->py][map->px - 1] != 'E')
	{
		if (map->split_map[map->py][map->px - 1] == 'O' ||
			map->split_map[map->py][map->px - 1] == 'T' ||
			map->split_map[map->py][map->px - 1] == 't')
			closewin(map);
		if (map->pl_dir == 0)
		{
			if (map->supergoku == 0)
			{
				put_imagen_xpm(map, "./sprites/suelo_ok.xpm", map->py, map->px);
				put_imagen_xpm(map, "./sprites/goku_left.xpm",
					map->py, map->px);
				map->pl_dir = 1;
			}
			else
			{
				put_imagen_xpm(map, "./sprites/suelo_ok.xpm", map->py, map->px);
				put_imagen_xpm(map, "./sprites/supergoku_left.xpm",
					map->py, map->px);
				map->pl_dir = 1;
			}
		}
		if (map->split_map[map->py][map->px - 1] == 'C')
		{
			map->n_collect -= 1;
			map->frame_exit = 0;
		}
		map->n_frames = 0;
		map->keycode_c = keycode;
		*i = 1;
	}
}

void	key_y(int keycode, t_map *map, int *i)
{
	if (keycode == 13 && map->split_map[map->py - 1][map->px] != '1' &&
		map->split_map[map->py -1][map->px] != 'E')
	{
		if (map->split_map[map->py - 1][map->px] == 'O' ||
			map->split_map[map->py - 1][map->px] == 'T' ||
			map->split_map[map->py - 1][map->px] == 't')
			closewin(map);
		if (map->split_map[map->py -1][map->px] == 'C')
		{
			map->n_collect -= 1;
			map->frame_exit = 0;
		}
		map->n_frames = 0;
		map->keycode_c = keycode;
		*i = 1;
	}
	if (keycode == 1 && map->split_map[map->py + 1][map->px] != '1' &&
		map->split_map[map->py + 1][map->px] != 'E')
	{
		if (map->split_map[map->py + 1][map->px] == 'O' ||
			map->split_map[map->py + 1][map->px] == 'T' ||
			map->split_map[map->py + 1][map->px] == 't')
			closewin(map);
		if (map->split_map[map->py + 1][map->px] == 'C')
		{
			map->n_collect -= 1;
			map->frame_exit = 0;
		}
		map->n_frames = 0;
		map->keycode_c = keycode;
		*i = 1;
	}
}
