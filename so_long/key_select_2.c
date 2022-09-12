/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_select_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:51:38 by daparici          #+#    #+#             */
/*   Updated: 2022/09/12 11:08:17 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_x_right(int keycode, t_map *map)
{
	if (keycode == 2 && map->split_map[map->py][map->px + 1] != '1' &&
		map->split_map[map->py][map->px + 1] != 'E')
	{
		if (map->split_map[map->py][map->px + 1] == 'O' ||
			map->split_map[map->py][map->px + 1] == 'T' ||
			map->split_map[map->py][map->px + 1] == 't')
			closewin(map);
		if (map->pl_dir == 1)
			key_x_right_2(map);
		if (map->split_map[map->py][map->px + 1] == 'C')
		{
			map->n_collect -= 1;
			map->frame_exit = 0;
		}
		map->n_frames = 0;
		map->keycode_c = keycode;
		map->score++;
		print_score(map->score);
	}
}

void	key_x_right_2(t_map *map)
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

void	key_x_left(int keycode, t_map *map)
{
	if (keycode == 0 && map->split_map[map->py][map->px - 1] != '1' &&
		map->split_map[map->py][map->px - 1] != 'E')
	{
		if (map->split_map[map->py][map->px - 1] == 'O' ||
			map->split_map[map->py][map->px - 1] == 'T' ||
			map->split_map[map->py][map->px - 1] == 't')
			closewin(map);
		if (map->pl_dir == 0)
			key_x_left_2(map);
		if (map->split_map[map->py][map->px - 1] == 'C')
		{
			map->n_collect -= 1;
			map->frame_exit = 0;
		}
		map->n_frames = 0;
		map->keycode_c = keycode;
		map->score++;
		print_score(map->score);
	}
}

void	key_x_left_2(t_map *map)
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
