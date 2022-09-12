/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_select.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:37:52 by daparici          #+#    #+#             */
/*   Updated: 2022/09/12 12:31:44 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_x(int keycode, t_map *map)
{
	key_x_left(keycode, map);
	key_x_right(keycode, map);
}

void	key_y(int keycode, t_map *map)
{
	if (keycode == 13 && map->split_map[map->py - 1][map->px] != '1' &&
		map->split_map[map->py -1][map->px] != 'E')
	{
		if (map->split_map[map->py - 1][map->px] == 'O')
		{
			map->exit_open = 0;
			closewin(map);
		}
		if (map->split_map[map->py - 1][map->px] == 'T' ||
			map->split_map[map->py - 1][map->px] == 't')
			closewin(map);
		if (map->split_map[map->py -1][map->px] == 'C')
		{
			map->n_collect -= 1;
			map->frame_exit = 0;
		}
		map->n_frames = 0;
		map->keycode_c = keycode;
		map->moves++;
		print_moves(map->moves);
	}
	if (keycode == 1 && map->split_map[map->py + 1][map->px] != '1' &&
		map->split_map[map->py + 1][map->px] != 'E')
		key_y_2(keycode, map);
}

void	key_y_2(int keycode, t_map *map)
{
	if (map->split_map[map->py + 1][map->px] == 'O')
	{
		map->exit_open = 0;
		closewin(map);
	}
	if (map->split_map[map->py + 1][map->px] == 'T' ||
		map->split_map[map->py + 1][map->px] == 't')
		closewin(map);
	if (map->split_map[map->py + 1][map->px] == 'C')
	{
		map->n_collect -= 1;
		map->frame_exit = 0;
	}
	map->n_frames = 0;
	map->keycode_c = keycode;
	map->moves++;
	print_moves(map->moves);
}

void	print_moves(int moves)
{
	ft_printf("Numero de movimientos: %i\n", moves);
}
