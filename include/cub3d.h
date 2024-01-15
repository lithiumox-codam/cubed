/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/17 16:08:19 by mdekker       #+#    #+#                 */
/*   Updated: 2024/01/15 18:37:05 by maxvalk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <MLX42.h>
# include <libft.h>
# include <structs.h>
# include <config.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>

bool	init(t_data *data, char *file);
bool	check_floor(t_data *data);
int		get_rgba(char *str);


/**
 * MLX functions
*/
int		init_window(t_data *data);

/*
 ** Parser
 */
bool	parse(t_data *data);
bool	apply_strings_to_array(t_data *data, size_t *i);
bool	create_2d_arr(t_data *data);
void	get_w_and_h(t_data *data, size_t *i);
bool	handle_path(char *str, t_info_types type, t_data *data);
bool	handle_rgba(char *str, t_info_types type, t_data *data);
/*
 ** Debug
 */
void	print_array(t_data *data);
#endif
