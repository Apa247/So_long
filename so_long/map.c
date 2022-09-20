/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:31:15 by daparici          #+#    #+#             */
/*   Updated: 2022/09/20 12:47:55 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	put_imagen_map(t_map *map)
{
	int	i;
	int	k;

	i = -1;
	while (map->split_map[++i])
	{
		k = -1;
		while (map->split_map[i][++k])
		{
			if (map->split_map[i][k] == '1')
				put_walls(map, i, k);
			put_other_map(map, i, k);
		}
	}
	return (1);
}

void	put_walls(t_map *map, int i, int k)
{
	if (i == 0 && k == 0)
		put_imagen_xpm(map, "./sprites/esquina_izq_up.xpm", i, k);
	else if (i == 0 && k > 0 && k < map->n_col - 1)
		put_imagen_xpm(map, "./sprites/lado_up.xpm", i, k);
	else if (i == 0 && k == map->n_col - 1)
		put_imagen_xpm(map, "./sprites/esquina_der_up.xpm", i, k);
	else if (k == 0 && i > 0 && i < map->n_row - 1)
		put_imagen_xpm(map, "./sprites/lado_izq.xpm", i, k);
	else if (i == map->n_row - 1 && k == 0)
		put_imagen_xpm(map, "./sprites/esquina_izq_down.xpm", i, k);
	else if (i == map->n_row - 1 && k > 0 && k < map->n_col - 1)
		put_imagen_xpm(map, "./sprites/lado_abj.xpm", i, k);
	else if (i == map->n_row - 1 && k == map->n_col - 1)
		put_imagen_xpm(map, "./sprites/esquina_der_down.xpm", i, k);
	else if (k == map->n_col - 1 && i > 0 && i < map->n_row - 1)
		put_imagen_xpm(map, "./sprites/lado_der.xpm", i, k);
	else
	{
		put_imagen_xpm(map, "./sprites/suelo_ok.xpm", i, k);
		put_imagen_xpm(map, "./sprites/pared_ok.xpm", i, k);
	}
}

void	put_other_map(t_map *map, int i, int k)
{
	if (map->split_map[i][k] == '0')
		put_imagen_xpm(map, "./sprites/suelo_ok.xpm", i, k);
	if (map->split_map[i][k] == 'T')
	{
		put_imagen_xpm(map, "./sprites/suelo_ok.xpm", i, k);
		put_imagen_xpm(map, "./sprites/bubu_right.xpm", i, k);
	}
	if (map->split_map[i][k] == 'C')
	{
		put_imagen_xpm(map, "./sprites/suelo_ok.xpm", i, k);
		put_imagen_xpm(map, "./sprites/coleccionable.xpm", i, k);
	}
	if (map->split_map[i][k] == 'E')
	{
		put_imagen_xpm(map, "./sprites/suelo_ok.xpm", i, k);
		put_imagen_xpm(map, "./sprites/capsula.xpm", i, k);
	}
	if (map->split_map[i][k] == 'P')
	{
		put_imagen_xpm(map, "./sprites/suelo_ok.xpm", i, k);
		put_imagen_xpm(map, "./sprites/goku_buena.xpm", i, k);
	}
}
