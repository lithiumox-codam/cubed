/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/17 16:20:25 by mdekker       #+#    #+#                 */
/*   Updated: 2024/03/19 15:59:11 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		return (error(ARGUMENTS, NULL), 1);
	data = ft_calloc(1, sizeof(t_data));
	if (!init(data, av[1]))
		return (free_all(data), 1);
	if (!parse(data))
		return (free_all(data), 1);
	if (!init_window(data))
		return (free_all(data), 1);
	free_all(data);
	return (0);
}
