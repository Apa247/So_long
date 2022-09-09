/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:17:28 by daparici          #+#    #+#             */
/*   Updated: 2022/09/09 18:09:43 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_next_frame(t_map *map)
{
	move_enemies(map);
	if ((map->keycode_c == 13 || map->keycode_c == 1))
	{
		if (map->supergoku == 0)
			move_goku_y(map);
		else
			move_supergoku_y(map);
	}
	if (map->keycode_c == 0 || map->keycode_c == 2)
		move_goku_x(map);
	if (map->n_collect == 0 && map->n_exit != 0)
		open_exit(map);
	if (map->ki == 1)
		power_ki(map);
	if (map->ki == 1 && map->n_collect == 0)
		super_power_ki(map);
	map->frame_exit++;
	map->n_frames++;
	map->frames_enemies++;
	if (map->copy_px == map->copy_enemy_x
		&& map->copy_py == map->copy_enemy_y)
		closewin(map);
	return (1);
}

void	start_game(t_map *map)
{
	map->mlx = mlx_init();
	map->mlx_window = mlx_new_window(map->mlx, map->n_col * SIZE, \
		map->n_row * SIZE, "So_long");
	put_imagen_map(map);
	mlx_hook(map->mlx_window, 17, 1L << 17, closewin, map);
	mlx_key_hook(map->mlx_window, key_select, map);
	mlx_loop_hook(map->mlx, render_next_frame, map);
	mlx_loop(map->mlx);
}

int	key_select(int keycode, t_map *map)
{
	int	i;

	i = 0;
	printf("%i\n", keycode);
	if (keycode == 53)
	{
		printf("finished!\n");
		exit(0);
		return (1);
	}
	if (map->n_frames > 1400 && map->ki == 0)
	{
		key_y(keycode, map, &i);
		key_x(keycode, map, &i);
	}
	return (i);
}

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
				put_imagen_xpm(map, "./sprites/capsula.xpm", i, k);
			if (map->split_map[i][k] == 'P')
			{
				put_imagen_xpm(map, "./sprites/suelo_ok.xpm", i, k);
				put_imagen_xpm(map, "./sprites/goku_buena.xpm", i, k);
			}
		}
	}
	return (1);
}

void	put_imagen_xpm(t_map *map, char *adress_img, int x, int y)
{
	void	*img;
	int		res;

	res = 47;
	map->width = (res * y);
	map->height = (res * x);
	img = mlx_xpm_file_to_image(map->mlx, adress_img,
			&res, &res);
	if (!img)
	{
		printf("ERROR\n");
		exit(1);
	}
	mlx_put_image_to_window(map->mlx, map->mlx_window, img,
		map->width, map->height);
	mlx_destroy_image(map->mlx, img);
}
