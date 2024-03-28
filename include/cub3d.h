/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/17 16:08:19 by mdekker       #+#    #+#                 */
/*   Updated: 2024/03/22 15:26:23 by maxvalk       ########   odam.nl         */
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
void			dda(t_data *data, t_raycast *ray);
void			calc_line(t_data *data, t_raycast *ray);
void			draw_tex_y(t_data *data, t_raycast *ray, mlx_texture_t *tex,
					int x);

bool			init(t_data *data, char *file);
bool			check_floor(t_data *data);
bool			get_rgba(int *res, char *str);
void			raycast(t_data *data, t_raycast *ray, unsigned int x);
mlx_texture_t	*texture(t_data *data, t_raycast *ray);

/**
 * MLX functions
 */
bool			init_window(t_data *data);
void			cursor_hook(double xpos, double ypos, void *param);
void			key_hook(void *param);
void			draw_sprite(t_data *data);
void			arrow_keys(t_data *data);

/**
 * Utils
 */
void			set_new_pos(t_data *data, t_player player, t_info_types dir,
					double incr);

/*
 ** Parser
 */
bool			parse(t_data *data);
const t_func	*return_arr(void);
bool			apply_strings_to_array(t_data *data, int *i);
bool			create_2d_arr(t_data *data);
void			get_w_and_h(t_data *data, int *i);
bool			handle_path(char *str, t_info_types type, t_data *data);
bool			handle_rgba(char *str, t_info_types type, t_data *data);
bool			handle_sprite(char *str, t_info_types type, t_data *data);
bool			handle_door(char *str, t_info_types type, t_data *data);
bool			check_rgb(char *str);
bool			get_image(mlx_texture_t **img, char *path);
bool			get_sprites(t_vector *sprites, char *path);
bool			get_doors(t_textures *textures, char *path);
int				count_arr(char **arr);
bool			check_info(bool *arr);
bool			check_arr(t_info_types type, bool *arr);
bool			get_image(mlx_texture_t **img, char *path);
bool			str_ends_with(char *str, char *end);
/*
 ** Debug
 */
void			print_array(t_data *data);
void			print_data(t_data *data);

/*
 ** Error handling
 */
bool			error(const char *message, const char *extra);

/*
 ** Free functions
*/
void			free_all(t_data *data);
void			free_bonus(t_data *data);
void			free_sprite(void *texture);
void			free_if_not_null(mlx_texture_t *texture);
void			clear_2d_array(t_map_types **array, int height);

/*
 ** Bonus
 */
void			free_sprite(void *sprite);
void			clear_image(mlx_image_t *img);
void			draw_minimap(t_data *data);
void			draw_tex_door(t_data *data, t_raycast *ray, mlx_texture_t *tex,
					int x);
void			draw_tex_sprite(t_data *data, t_raycast *ray,
					mlx_texture_t *tex, int x);
void			set_bonus_ray(t_data *data, t_raycast *ray_og,
					t_map_types type);
bool			is_renderable(t_map_types type);

void			draw_square(t_data *data, int x, int y, int color);
void			draw_dot(mlx_image_t *img);
void			draw_line_player(mlx_image_t *img, t_data *data);

#endif
