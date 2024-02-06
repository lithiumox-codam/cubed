/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/17 16:08:19 by mdekker       #+#    #+#                 */
/*   Updated: 2024/02/02 18:39:33 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <MLX42.h>
# include <config.h>
# include <fcntl.h>
# include <libft.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <structs.h>
# include <time.h>
# include <unistd.h>

# ifndef DEBUG
#  define DEBUG 0
# endif // !DEBUG

/**
 * Ray casting
 */
void	dda(t_data *data, t_raycast *ray);
void	calc_line(t_data *data, t_raycast *ray);
void	draw_tex_y(t_data *data, t_raycast *ray, mlx_texture_t *tex, int x);

bool	init(t_data *data, char *file);
bool	check_floor(t_data *data);
bool		get_rgba(int *res, char *str);
// void	raycast(t_data *data, t_raycast *ray);
void	raycast(t_data *data, t_raycast *ray, unsigned int x);

/**
 * MLX functions
 */
int		init_window(t_data *data);
void	draw_line_from_angle(t_data *data, double start_x, double start_y,
			float angle, int len, int col);
void	draw_circle(mlx_image_t *img, int centerX, int centerY, int color);
void	draw_square(mlx_image_t *img, int x, int y, int size, int color);
void	draw_player(t_data *data);
void	cursor_hook(double xpos, double ypos, void *param);

/*
 ** Parser
 */
bool	parse(t_data *data);
bool	apply_strings_to_array(t_data *data, int *i);
bool	create_2d_arr(t_data *data);
void	get_w_and_h(t_data *data, int *i);
bool	handle_path(char *str, t_info_types type, t_data *data);
bool	handle_rgba(char *str, t_info_types type, t_data *data);
bool	handle_sprite(char *str, t_info_types type, t_data *data);
bool	handle_door(char *str, t_info_types type, t_data *data);
bool	check_rgb(char *str);
bool   get_image(mlx_texture_t **img, char *path);
bool  get_sprites(t_vector *sprites, char *path);
int		count_arr(char **arr);

/*
 ** Debug
 */
void	print_array(t_data *data);
void	print_data(t_data *data);

/*
 ** Error handling
 */
bool    error(char *message, char *extra);
#endif
