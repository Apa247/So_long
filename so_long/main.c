/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:27:41 by daparici          #+#    #+#             */
/*   Updated: 2022/09/09 14:27:21 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_msg(char *msg)
{
	printf("Error\n%s\n", msg);
	exit(0);
	return (0);
}

int	closewin(t_map *map)
{
	if (map->n_exit == 0)
	{
		printf("You win\n");
		exit (0);
		return (0);
	}
	printf("Finished\n");
	exit (0);
	if (map)
		return (0);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	map = (t_map *)ft_calloc(sizeof(t_map), 1);
	map = params_init(map);
	map = params_init_2(map);
	check_map(argc, argv, map);
	map->copy_n_enemies = map->n_enemies;
	start_game(map);
	printf("%s\n", "OK");
	return (0);
}

t_map	*params_init(t_map *map)
{
	map->n_row = 0;
	map->n_col = 0;
	map->n_exit = 0;
	map->n_pl = 0;
	map->px = 0;
	map->py = 0;
	map->copy_px = 0;
	map->copy_py = 0;
	map->n_enemies = 0;
	map->copy_n_enemies = 0;
	map->enemies_copy = 0;
	map->frames_enemies = 0;
	map->enemy_x = 0;
	map->enemy_y = 0;
	map->copy_enemy_x = 1;
	map->copy_enemy_y = 1;
	map->enemy_dir_x = 0;
	map->enemy_dir_y = 0;
	return (map);
}

t_map	*params_init_2(t_map *map)
{
	map->pl_dir = 0;
	map->keycode_c = 1000;
	map->n_collect = 0;
	map->exit_open = 1;
	map->e_x = 0;
	map->e_y = 0;
	map->frame_exit = 0;
	map->ki = 0;
	map->supergoku = 0;
	map->n_frames = 0;
	map->n_moves = 0;
	map->width = 0;
	map->height = 0;
	return (map);
}
