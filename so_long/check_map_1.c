/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:12:36 by daparici          #+#    #+#             */
/*   Updated: 2022/07/18 20:08:46 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(int argc, char **argv, t_map *map)
{
	int	fd;

	if (argc != 2)
		error_msg("Invalid number of arguments");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_msg("File not found");
	check_map_name(argv);
	check_map_params(fd, map);
}

void	check_map_name(char **argv)
{
	char	*name_map;

	name_map = strchr(argv[1], '.');
	if (strcmp(name_map, ".ber"))
		error_msg("Invalid type file, please use .ber");
}

void	check_map_params(int fd, t_map *map)
{
	char	*map_str;

	map_str = ft_strdup("");
	ft_read_map(fd, map, &map_str);
	map->split_map = ft_split(map_str, '\n');
	if (!map)
		error_msg("Memory allocation error!");
	close(fd);
	free(map_str);
	check_map_error(map);
	if (map->n_collect < 1 || map->n_exit < 1 || map->n_pl < 1)
		error_msg("Missing parameters");
}
