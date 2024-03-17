/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/17 16:08:19 by mdekker       #+#    #+#                 */
/*   Updated: 2024/03/17 02:57:51 by maxvalk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <MLX42.h>
#include <config.h>
#include <fcntl.h>
#include <libft.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <structs.h>
#include <time.h>
#include <unistd.h>

#ifndef DEBUG
#define DEBUG 0
#endif // !DEBUG

/**
 * Ray casting
 */
void dda(t_data *data, t_raycast *ray);
void calc_line(t_data *data, t_raycast *ray);
void draw_tex_y(t_data *data, t_raycast *ray, mlx_texture_t *tex,
				int x);

bool init(t_data *data, char *file);
bool check_floor(t_data *data);
bool get_rgba(int *res, char *str);
// void	raycast(t_data *data, t_raycast *ray);
void raycast(t_data *data, t_raycast *ray, unsigned int x);
mlx_texture_t *determine_texture(t_data *data, t_raycast *ray);

/**
 * MLX functions
 */
bool init_window(t_data *data);
void draw_line_from_angle(t_data *data, double start_x,
						  double start_y, float angle, int len, int col);
void cursor_hook(double xpos, double ypos, void *param);
void key_hook(void *param);
void draw_sprite(t_data *data);

/**
 * Utils
 */
void set_new_pos(t_data *data, t_player player, t_info_types dir,
				 double incr);

/*
 ** Parser
 */
bool parse(t_data *data);
bool apply_strings_to_array(t_data *data, int *i);
bool create_2d_arr(t_data *data);
void get_w_and_h(t_data *data, int *i);
bool handle_path(char *str, t_info_types type, t_data *data);
bool handle_rgba(char *str, t_info_types type, t_data *data);
bool handle_sprite(char *str, t_info_types type, t_data *data);
bool handle_door(char *str, t_info_types type, t_data *data);
bool check_rgb(char *str);
bool get_image(mlx_texture_t **img, char *path);
bool get_sprites(t_vector *sprites, char *path);
bool get_doors(t_textures *textures, char *path);
int count_arr(char **arr);
bool	str_ends_with(char *str, char *end);

/*
 ** Debug
 */
void print_array(t_data *data);
void print_data(t_data *data);

/*
 ** Error handling
 */
bool error(const char *message, const char *extra);

/*
 ** Bonus
 */
void free_sprite(void *sprite);
void draw_minimap(t_data *data);
#endif
