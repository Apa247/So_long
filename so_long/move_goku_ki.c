/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_goku_ki.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:34:31 by daparici          #+#    #+#             */
/*   Updated: 2022/07/27 18:49:15 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_frame(unsigned long frame, t_map *map, char *image)
{
	if (map->n_frames == frame)
	{
		put_imagen_xpm(map, "./sprites/suelo.xpm", map->py, map->px);
		put_imagen_xpm(map, image, map->py, map->px);
		if (map->n_frames == 5400 && map->n_collect != 0)
			map->ki = 0;
		if (map->n_frames == 10000 && map->n_collect == 0)
		{
			map->ki = 0;
			map->supergoku = 1;
		}
	}
}

void	power_ki(t_map *map)
{
	if (map->pl_dir == 0)
	{
		move_frame(1400, map, "./sprites/goku_transf1.xpm");
		move_frame(2000, map, "./sprites/goku_transf2.xpm");
		move_frame(2600, map, "./sprites/goku_transf3.xpm");
		move_frame(3200, map, "./sprites/goku_ki1.xpm");
		move_frame(3600, map, "./sprites/goku_ki2.xpm");
		move_frame(4200, map, "./sprites/goku_ki3.xpm");
		move_frame(4600, map, "./sprites/goku_ki3_final.xpm");
		move_frame(5400, map, "./sprites/goku_buena.xpm");
	}
	else
	{
		move_frame(1400, map, "./sprites/goku_transf1_left.xpm");
		move_frame(2000, map, "./sprites/goku_transf2_left.xpm");
		move_frame(2600, map, "./sprites/goku_transf3_left.xpm");
		move_frame(3200, map, "./sprites/goku_ki1_left.xpm");
		move_frame(3600, map, "./sprites/goku_ki2_left.xpm");
		move_frame(4200, map, "./sprites/goku_ki3_left.xpm");
		move_frame(4600, map, "./sprites/goku_ki3_final_left.xpm");
		move_frame(5400, map, "./sprites/goku_left.xpm");
	}
}

void	super_power_ki(t_map *map)
{
	if (map->pl_dir == 0)
	{
		move_frame(6000, map, "./sprites/supergoku_ki1.xpm");
		move_frame(7000, map, "./sprites/supergoku_ki2.xpm");
		move_frame(8000, map, "./sprites/supergoku_ki3.xpm");
		move_frame(9000, map, "./sprites/supergoku_ki4.xpm");
		move_frame(10000, map, "./sprites/supergoku_right.xpm");
	}
	else
	{
		move_frame(6000, map, "./sprites/supergoku_ki1_left.xpm");
		move_frame(7000, map, "./sprites/supergoku_ki2_left.xpm");
		move_frame(8000, map, "./sprites/supergoku_ki3_left.xpm");
		move_frame(9000, map, "./sprites/supergoku_ki4_left.xpm");
		move_frame(10000, map, "./sprites/supergoku_left.xpm");
	}
}
