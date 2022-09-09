/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:17:28 by daparici          #+#    #+#             */
/*   Updated: 2022/08/04 12:17:33 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_exit(t_map *map)
{
	int	i;
	int	k;

	i = -1;
	while (map->split_map[++i] && map->frame_exit == 100 && map->n_exit != 0)
	{
		k = -1;
		while (map->split_map[i][++k])
		{
			if (map->split_map[i][k] == 'E')
			{
				map->e_x = k;
				map->e_y = i;
				break ;
			}
		}
	}
	open_exit_2(map);
}

void	open_exit_2(t_map *map)
{
	if (map->frame_exit == 800 && map->n_exit != 0)
		put_imagen_xpm(map, "./sprites/puff.xpm", map->e_y, map->e_x);
	if (map->frame_exit == 1600 && map->n_exit != 0)
	{
		put_imagen_xpm(map, "./sprites/suelo.xpm", map->e_y, map->e_x);
		put_imagen_xpm(map, "./sprites/puff2.xpm", map->e_y, map->e_x);
	}
	if (map->frame_exit == 2400 && map->n_exit != 0)
	{
		put_imagen_xpm(map, "./sprites/salida.xpm", map->e_y, map->e_x);
		map->split_map[map->e_y][map->e_x] = 'O';
		map->n_exit -= 1;
		if (map->n_exit != 0)
			map->frame_exit = 99;
		if (map->n_exit == 0)
			map->frame_exit = 5601;
		// {
		// 	map->exit_open = 1;
		// }
	}
}
