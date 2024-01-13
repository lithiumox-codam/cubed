/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/17 16:08:19 by mdekker       #+#    #+#                 */
/*   Updated: 2024/01/13 17:36:36 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <MLX42.h>
# include <fcntl.h>
# include <libft.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <structs.h>
# include <unistd.h>

bool	init(t_data *data, char *file);
bool	check_floor(t_data *data);

/*
 ** Parser
 */
bool	parse(t_data *data);
bool	apply_strings_to_array(t_data *data, size_t *i);
bool	create_2d_arr(t_data *data);
void	get_w_and_h(t_data *data, size_t *i);
bool	handle_no(char *str, t_data *data);
bool	handle_so(char *str, t_data *data);
bool	handle_we(char *str, t_data *data);
bool	handle_ea(char *str, t_data *data);
bool	handle_f(char *str, t_data *data);
bool	handle_c(char *str, t_data *data);

/*
 ** Debug
 */
void	print_array(t_data *data);
#endif
