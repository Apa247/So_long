/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:31:21 by daparici          #+#    #+#             */
/*   Updated: 2022/07/29 16:42:41 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_read_map(int fd, t_map *map, char **map_str)
{
	char	*line;
	char	*last_line;

	line = NULL;
	last_line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			if (map->n_row < 3 && map->n_col < 3)
				error_msg("Map is empty!");
			free(last_line);
			break ;
		}
		free(last_line);
		if (!map->n_col)
			map->n_col = ft_strlen(line) - 1;
		last_line = ft_substr(line, 0, ft_strlen(line));
		free(line);
		*map_str = ft_strjoin(*map_str, last_line);
		map->n_row++;
	}
}

void	ft_count_params(t_map *map, int i, int k)
{
	if (map->split_map[i][k] == 'T')
		map->n_enemies += 1;
	if (map->split_map[i][k] == 'E')
		map->n_exit += 1;
	if (map->split_map[i][k] == 'C')
		map->n_collect += 1;
	if (map->split_map[i][k] == 'P')
	{
		printf("%d\n%d\n", i, k);
		map->n_pl += 1;
		map->py = i;
		map->px = k;
		printf("%i\n%i\n", map->px, map->py);
	}
}

int	check_map_error(t_map *map)
{
	int	i;
	int	k;

	i = -1;
	while (map->split_map[++i])
	{
		k = -1;
		if (ft_strlen(map->split_map[0]) != ft_strlen(map->split_map[i]))
			error_msg("Map must be rectangular!");
		while (map->split_map[i][++k])
		{
			ft_count_params(map, i, k);
			if (map->split_map[0][k] != '1' ||
				map->split_map[map->n_row - 1][k] != '1'
				|| map->split_map[i][0] != '1' ||
				map->split_map[i][map->n_col - 1] != '1')
				error_msg("Map must be surrounded by walls!");
			if (map->split_map[i][k] != '0' && map->split_map[i][k] != '1' &&
					map->split_map[i][k] != 'P' && map->split_map[i][k] != 'C'
					&& map->split_map[i][k] != 'E' &&
					map->split_map[i][k] != 'T')
				error_msg("Invalid map, check parameters");
		}
	}
	return (0);
}
