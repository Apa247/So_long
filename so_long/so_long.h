/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:16:01 by daparici          #+#    #+#             */
/*   Updated: 2022/08/14 20:29:17 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define SIZE 47

# include <ctype.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <xlocale.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <mlx.h>
//# include "./mlx/mlx.h"
# include "./Libft/libft.h"
# include "./GetNextLine/get_next_line.h"
# include <OpenGL/gl.h>
# include <OpenGl/glu.h>
# include <GLUT/glut.h>

typedef struct s_map
{
	void			*mlx;
	void			*mlx_window;
	char			**split_map;
	int				n_row;
	int				n_col;
	int				n_exit;
	int				n_pl;
	int				n_enemies;
	int				copy_n_enemies;
	int				enemies_copy;
	int				frames_enemies;
	int				enemy_x;
	int				enemy_y;
	int				copy_enemy_x;
	int				copy_enemy_y;
	int				enemy_dir_y;
	int				enemy_dir_x;
	int				move_enemy_y;
	int				move_enemy_x;
	int				px;
	int				py;
	int				copy_px;
	int				copy_py;
	int				pl_dir;
	int				keycode_c;
	int				ki;
	int				supergoku;
	int				n_collect;
	int				frame_exit;
	int				exit_open;
	int				e_x;
	int				e_y;
	int				n_moves;
	unsigned long	n_frames;
	int				width;
	int				height;
}				t_map;

int		error_msg(char *msg);
void	check_map(int argc, char **argv, t_map *map);
void	check_map_name(char **argv);
void	check_map_params(int fd, t_map *map);
void	ft_read_map(int fd, t_map *map, char **map_str);
void	ft_count_params(t_map *map, int i, int k);
int		check_map_error(t_map *map);
t_map	ft_initmap(void);
void	start_game(t_map *map);
int		put_imagen_map(t_map *map);
void	get_type_params(t_map map, int i, int k);
void	put_imagen_xpm(t_map *map, char *adress_img, int x, int y);
t_map	*params_init(t_map *map);
t_map	*params_init_2(t_map *map);
//void	freemap(t_map *map);
int		closewin(t_map *map);
int		key_select(int keycode, t_map *map);
int		render_next_frame(t_map *map);
void	key_y(int keycode, t_map *map, int *i);
void	key_x(int keycode, t_map *map, int *i);
void	put_goku_map(t_map *map);
void	move_goku_y(t_map *map);
void	move_goku_x(t_map *map);
void	move_goku_x_right(t_map *map);
void	move_goku_x_left(t_map *map);
void	open_exit(t_map *map);
void	open_exit_2(t_map *map);
void	power_ki(t_map *map);
void	key_x_left(int keycode, t_map *map, int *i);
void	key_x_right(int keycode, t_map *map, int *i);
void	super_power_ki(t_map *map);
void	move_frame(unsigned long frame, t_map *map, char *image);
void	put_goku_map_x(t_map *map);
void	put_goku_map_y(t_map *map);
void	move_supergoku_y(t_map *map);
void	put_supergoku_map_y(t_map *map);
void	move_supergoku_x_left(t_map *map);
void	move_supergoku_x_right(t_map *map);
void	put_supergoku_map_x(t_map *map);
void	move_enemies(t_map *map);
void	move_enemies_2(t_map *map, int i, int k);
void	move_enemy_y(t_map *map);
void	move_enemy_x(t_map *map);
void	move_enemy_frame(int frame, t_map *map, char *image);

#endif
