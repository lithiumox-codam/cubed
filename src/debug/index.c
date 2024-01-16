/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   index.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/04 13:32:43 by mdekker       #+#    #+#                 */
/*   Updated: 2024/01/16 17:24:25 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * @brief Prints the array to the terminal
 *
 * @param data The main struct
 */
void	print_array(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	if (!DEBUG)
		return ;
	while (i < data->map.height)
	{
		j = 0;
		while (j < data->map.width)
		{
			if (data->map.array[i][j] == WALL)
				printf("🟥");
			else if (data->map.array[i][j] == FLOOR)
				printf("⬜️");
			else if (data->map.array[i][j] == PLAYER)
				printf("👶");
			else if (data->map.array[i][j] == EMPTY)
				printf("⬛️");
			j++;
		}
		printf("\n");
		i++;
	}
}

static int	shift(int num, int shift)
{
	return ((num >> shift) & 0xFF);
}

static void	print_floor_and_ceiling(t_textures *t)
{
	int	r;
	int	g;
	int	b;

	r = shift(t->floor, 16);
	g = shift(t->floor, 8);
	b = shift(t->floor, 0);
	printf("  \033[1;33mfloor:\033[0m ");
	printf("\033[48;2;%d;%d;%dm  \033[0m\n", r, g, b);
	r = shift(t->ceiling, 16);
	g = shift(t->ceiling, 8);
	b = shift(t->ceiling, 0);
	printf("  \033[1;33mceiling:\033[0m ");
	printf("\033[48;2;%d;%d;%dm  \033[0m\n\n", r, g, b);
}

void	print_data(t_data *data)
{
	if (!DEBUG)
		return ;
	printf("\n");
	printf("\033[1;36mMap:\033[0m\n");
	printf("  \033[1;33mwidth:\033[0m %d\n", data->map.width);
	printf("  \033[1;33mheight:\033[0m %d\n\n", data->map.height);
	printf("\033[1;36mTextures:\033[0m\n");
	printf("  \033[1;33mWall:\033[0m\n");
	printf("    \033[1;33mnorth:\033[0m %p\n", data->textures.wall.north);
	printf("    \033[1;33msouth:\033[0m %p\n", data->textures.wall.south);
	printf("    \033[1;33meast:\033[0m %p\n", data->textures.wall.east);
	printf("    \033[1;33mwest:\033[0m %p\n", data->textures.wall.west);
	print_floor_and_ceiling(&data->textures);
	printf("\033[1;36mPlayer:\033[0m\n");
	printf("  \033[1;33mx:\033[0m %f\n", data->player.x);
	printf("  \033[1;33my:\033[0m %f\n", data->player.y);
	printf("  \033[1;33mdir:\033[0m %f\n", data->player.dir);
}